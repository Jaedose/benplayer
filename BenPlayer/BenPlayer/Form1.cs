using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Media;
using System.IO;
using System.Diagnostics;
using System.Net;
using System.Collections.Specialized;
using System.Reflection;



namespace BenPlayer
{
    public partial class Form1 : Form
    {
        private bool isDragging = false;
        private int initialX;
        private int initialVolume;
        private List<string> playlist = new List<string>();
        private int currentTrackIndex = -1;

        

        public Form1()
        {
            InitializeComponent();
            // Set initial volume to half
            axWindowsMediaPlayer1.settings.volume = 50;
            UpdateVolumeIndicator(50);

            // Set initial width of the volume panel to half of the maximum width
            panelVolume.Width = 104 / 2;
            
            
        }

        private void CheckForUpdates()
        {
            // Pre-set version (replace with your actual version)
            string currentVersion = "1.1.1";

            // Construct URL with version parameter
            string updateCheckUrl = "http://ec2-15-229-12-201.sa-east-1.compute.amazonaws.com/benupdate?version=" + currentVersion;

            HttpWebRequest request = null;
            try
            {
                request = (HttpWebRequest)WebRequest.Create(updateCheckUrl);
                request.Method = "POST";

                HttpWebResponse response = (HttpWebResponse)request.GetResponse();

                using (Stream responseStream = response.GetResponseStream())
                using (StreamReader reader = new StreamReader(responseStream))
                {
                    string responseBody = reader.ReadToEnd();

                    // Handle response logic
                    if (responseBody == "1")
                    {
                        MessageBox.Show("An update is available!");
                    }
                    else if (responseBody == "0")
                    {
                        MessageBox.Show("The application is up to date.");
                    }
                    else
                    {
                        MessageBox.Show(responseBody, "Check Successful");
                    }
                }
            }
            catch (WebException ex)
            {
                MessageBox.Show("Error checking for updates: " + ex.Message, "Check Failed");
            }
            catch (Exception ex) // Catch other potential exceptions
            {
                MessageBox.Show("An unexpected error occurred: " + ex.Message, "Error");
            }
            finally
            {
                // Ensure request is disposed
                if (request != null)
                {
                    request.Abort();
                }
            }
        }



        private void btnPlay_Click(object sender, EventArgs e)
        {
            // Check if there are tracks in the playlist
            if (playlist.Count > 0)
            {
                // Set the current track index to 0 (first track) if it's not already set
                if (currentTrackIndex == -1)
                {
                    currentTrackIndex = 0;
                }
                // Call the PlayCurrentTrack function
                PlayCurrentTrack();
            }
            else
            {
                MessageBox.Show("No tracks in the playlist.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void PlayCurrentTrack()
        {
            try
            {
                axWindowsMediaPlayer1.URL = playlist[currentTrackIndex];
                axWindowsMediaPlayer1.Ctlcontrols.play();
                CurrentlyPlaying.Text = "Currently playing: " + Path.GetFileName(playlist[currentTrackIndex]);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error playing track: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void CurrentlyPlaying_Click(object sender, EventArgs e)
        {

        }

        private void axWindowsMediaPlayer1_Enter(object sender, EventArgs e)
        {

        }

        private void btnPause_Click(object sender, EventArgs e)
        {
            if (axWindowsMediaPlayer1.playState == WMPLib.WMPPlayState.wmppsPlaying)
            {
                axWindowsMediaPlayer1.Ctlcontrols.pause();
                btnPause.Text = "Resume"; // Change button text to indicate that it will resume playback
            }
            else if (axWindowsMediaPlayer1.playState == WMPLib.WMPPlayState.wmppsPaused)
            {
                axWindowsMediaPlayer1.Ctlcontrols.play();
                btnPause.Text = "Pause"; // Change button text back to "Pause"
            }
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            axWindowsMediaPlayer1.Ctlcontrols.stop();
            CurrentlyPlaying.Text = "Nothing playing";
        }

        private void btnNext_Click(object sender, EventArgs e)
        {
            if (playlist.Count > 0)
            {
                currentTrackIndex = (currentTrackIndex + 1) % playlist.Count;
                PlayCurrentTrack();
            }
        }

        private void btnPrevious_Click(object sender, EventArgs e)
        {
            if (playlist.Count > 0)
            {
                currentTrackIndex = (currentTrackIndex - 1 + playlist.Count) % playlist.Count;
                PlayCurrentTrack();
            }
        }

        private void axWindowsMediaPlayer1_PlayStateChange(object sender, AxWMPLib._WMPOCXEvents_PlayStateChangeEvent e)
        {
            // Check if the new play state is "MediaEnded"
            if ((WMPLib.WMPPlayState)e.newState == WMPLib.WMPPlayState.wmppsMediaEnded)
            {
                if (playlist.Count > 0)
                {
                    currentTrackIndex = (currentTrackIndex + 1) % playlist.Count;
                    PlayCurrentTrack();
                }
            }
        }



        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            AboutForm aboutForm = new AboutForm();
            aboutForm.ShowDialog();
        }
        private void panelVolume_MouseDown(object sender, MouseEventArgs e)
        {
            isDragging = true;
            initialX = e.X;
            initialVolume = axWindowsMediaPlayer1.settings.volume;
        }

        private void panelVolume_MouseMove(object sender, MouseEventArgs e)
        {
            if (isDragging)
            {
                int halfWidth = 104 / 2; // Half of the initial width
                int deltaX = e.X - initialX;

                if (panelVolume.Width <= 1) // If the width is very small
                {
                    // Show the unmute button
                    buttonUnmute.Visible = true;
                }
                else
                {
                    buttonUnmute.Visible = false; // Hide the unmute button
                    int newVolume = initialVolume + deltaX * 800 / halfWidth; // Adjust volume based on mouse movement
                    // Double the adjustment factor from 200 to 400

                    // Adjust the volume within valid range
                    newVolume = Math.Max(0, Math.Min(800, newVolume)); // Adjusted maximum volume
                    axWindowsMediaPlayer1.settings.volume = newVolume;
                    UpdateVolumeIndicator(newVolume);
                }
            }
        }

        private void buttonUnmute_Click(object sender, EventArgs e)
        {
            // Set volume to half
            axWindowsMediaPlayer1.settings.volume = 400;
            UpdateVolumeIndicator(50);

            // Set panel width to half of the initial size
            panelVolume.Width = 104 / 2;

            // Hide the unmute button
            buttonUnmute.Visible = false;
        }

        private void panelVolume_MouseUp(object sender, MouseEventArgs e)
        {
            isDragging = false;
        }

        private void UpdateVolumeIndicator(int volume)
        {
            // Adjust the width of the volume panel to represent the volume level
            int width = (volume * 104) / 800; // Adjusted maximum volume
            panelVolume.Size = new Size(width, panelVolume.Height);
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void btnAddToPlaylist_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "Audio Files|*.wav;*.mp3";
            openFileDialog.Multiselect = true;

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                foreach (string filename in openFileDialog.FileNames)
                {
                    playlist.Add(filename);
                    listBoxPlaylist.Items.Add(Path.GetFileName(filename));
                }
            }
        }

        private void btnRemoveFromPlaylist_Click(object sender, EventArgs e)
        {
            if (listBoxPlaylist.SelectedIndex != -1)
            {
                int selectedIndex = listBoxPlaylist.SelectedIndex;
                playlist.RemoveAt(selectedIndex);
                listBoxPlaylist.Items.RemoveAt(selectedIndex);
            }
        }

        private void btnClearPlaylist_Click(object sender, EventArgs e)
        {
            playlist.Clear();
            listBoxPlaylist.Items.Clear();
        }

        private void checkForUpdatesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            CheckForUpdates();
        }

    }
}