<?php
// $q = $_REQUEST["q"];
$q = $_REQUEST["q"];
$mode = $_REQUEST["mode"];
exec('ds '.$q.' '.$mode, $output, $out);
// echo $output;
$a= $output;
$hint = "";

// lookup all hints from array if $q is different from ""
if ($q !== "") {
    $q = strtolower($q);
    foreach($a as $name) {
      if ($q!== $name) {
            $hint .= ", $name";
        }
    }
}
if (stripos( $hint, "incorrect" )) {
  exec('incorrect '.$q);
}

// Output "no suggestion" if no hint was found or output correct values
echo $hint === "" ? "no suggestion" : $hint;
?>
