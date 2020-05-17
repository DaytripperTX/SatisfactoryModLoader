echo off

set shouldLaunchGame=false

set "source=C:\Users\chad9\Desktop\SatisfactoryModLoader\Binaries\Win64"

set "destination=C:\Program Files\Epic Games\SatisfactoryEarlyAccess\mods"

set "Experimental=D:\Program Files\Epic Games\SatisfactoryExperimental\mods"

set "dll=UE4-ConfigLoader-Win64-Shipping.dll"

set "pdb=UE4-ConfigLoader-Win64-Shipping.pdb"

set config=%1

if "%1" == "Shipping" ( 
	echo Config mode is set to Shipping. The compiled dll and pdb will be copied to the mods folder
	robocopy "%source%" "%destination%" "%dll%" "%pdb%"
	robocopy "%source%" "%Experimental%" "%dll%" "%pdb%"
	
	if %shouldLaunchGame% == true (
		echo "launching game..."
		start "" "C:\Program Files\Epic Games\SatisfactoryEarlyAccess\FactoryGame.exe"
		exit
	)
	
	
	exit
) else (
	echo "Config mode is not set to Shipping. The compiled dll will not be copied "
)



exit