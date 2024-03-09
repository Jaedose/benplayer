<?php
// Retrieve client version (handle both GET and POST requests)
$clientVersion = isset($_GET['version']) ? $_GET['version'] : (isset($_POST['version']) ? $_POST['version'] : null);


$latestVersion = "1.1.1";

if ($clientVersion !== $latestVersion) {
    echo "An update is available, please visit the GitHub repository or the itch.io site to download it."; // Indicate an update is available
} else {
    echo "Your program is up to date."; // Indicate the client is up-to-date
}
?>