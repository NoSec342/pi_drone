O simpla drona realizate in c++ si arduino.
Drona este compusa dintr-un raspberry pi zero,un adaptor de retea wi-fi (orice adaptor), 
o placa de dezvoltare, un set de 4 motoare si o baterie.
<br>

[Instalare]
<br>
	Drona:<br>
	<code>
		sudo apt-get install git wiringpi 
		git clone https://github.com/NoSec342/pi_drone/
		cd pi_drone/ 
		./install.sh
	</code>
	Client:<br>
	<code>
		git clone https://github.com/NoSec342/pi_drone_client
		cd pi_drone_client/
		./install.sh
	</code>
[Utilizare]<br>
	Drona va fi setata in mod AP automat. Va trebui sa va conectati si rulati script-ul de pe client.
Pentru Setari este de recomandat sa accesati pagina web a acesteia din timpul utilizarii:<br> 
			http://192.168.0.1/login.php<br>
	Credentialele default vor fi admin:changeme, Este de recomandat sa fie schimbate cat mai repede.<br>

	Un alt mod de schimbare a setarilor ar fi editarea fisierului de configurare din /etc/pi_drone.conf


DE RETINUT, schimbarile setarilor nu vor avea efect decat dupa reboot!


PROIECTUL ACESTA ESTE INCA IN VERSIUNE ALPHA!



Proiect realizat de Slabu Andrei si Hutu Gabriel
