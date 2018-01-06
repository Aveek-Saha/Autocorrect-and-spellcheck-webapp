
<style>
  body{
    font-family: sans-serif;
    font-size: 12px;
    background: #000;
    padding: 25px;
    text-align: center;

  }
  p{
    color: white;
    margin-top: 5px;
    font-weight: 180;
    padding: 10px;
    margin-bottom: 1%;
    font-size: 3.5rem;
  }

</style>
<body>
<p>
  Word of the day is: <span></span>
</p>
</body>
<?php
$file= fopen('IncorrectWords.txt', 'r' );

$str = explode(",", fgets($file));

echo "<p style=\"color: white\">".$str[0]."</p>";
?>
