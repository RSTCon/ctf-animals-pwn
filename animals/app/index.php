<?php

if(isset($_POST['submit']))
{
	$numar = (int)$_POST['numar'];
	$numehex = bin2hex($_POST['nume']);

	if($numar >= 0 && $numar <=9)
	{
		print "<pre>";
		$cmd = "./animal " . $numar  . " " . $numehex . " ";
		system($cmd);
		print "</pre>";
	}
	else die("Numarul trebuie sa fie intre 0 si 9!");
}

// HTML

else
{

?>

<form method="post" action="animal.php">
Numar: <input type="text" name="numar" /><br />
Nume:  <input type="text" name="nume"><br />
<input type="submit" name="submit" value="Trimite" >
</form>

<?php

}

?>
