<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Sum Result</title>
</head>
<body>
    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $x = $_POST["x"];
        $y = $_POST["y"];
        $z = $_POST["z"];

        $sum = $x + $y + $z;

        echo "<p>The sum of $x, $y, and $z is: $sum</p>";
    }
    ?>
</body>
</html>
