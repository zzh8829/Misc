<?php
	$x = fgets(STDIN); 
	$n = fgets(STDIN);
	$m[0] = 0;
	for(int $i=1;$i<=x;$i++)
		$m[$i] = 99999;
	for(int $i=0;$i!=$n;$i++)
	{
		$t = fgets(STDIN);
		for(int $j=$t;$j<=$x;$j++)
			if($m[$j-$t]+1<$m[$j])
				$m[$j] = $m[$j-$t]+1;
	}
	echo $m[x]
?>