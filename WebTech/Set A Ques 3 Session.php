<?php
session_start();

if (!isset($_SESSION['counter'])) {
    $_SESSION['counter'] = 1;
} else {
    $_SESSION['counter']++;
}

$_SESSION['username'] = 'JohnDoe';

echo 'Counter: ' . $_SESSION['counter'] . '<br>';
echo 'Username: ' . $_SESSION['username'] . '<br>';

if (isset($_POST['destroy'])) {
    session_destroy();
    header("Location: ".$_SERVER['PHP_SELF']);
    exit();
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Session Example</title>
</head>
<body>
    <form method="post">
        <input type="submit" name="destroy" value="Destroy Session">
    </form>
</body>
</html>
