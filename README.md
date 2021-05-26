# PI_DRONE (PROIECT INCHIS)

O simpla drona realizate in c++ si arduino.
Drona este compusa dintr-un raspberry pi zero,un adaptor de retea wi-fi (orice adaptor), 
o placa de dezvoltare, un set de 4 motoare si o baterie.
## Instalare
Drona:
```bash
sudo apt-get install git wiringpi 
git clone https://github.com/NoSec342/pi_drone/
cd pi_drone/ 
./install.sh
```

## Usage
Drona va fi setata in mod AP automat. Va trebui sa va conectati si rulati script-ul de pe client, pe care il gasiti [aici](https://github.com/NoSec342/pi_drone_client/).
Pentru Setari este de recomandat sa accesati pagina web a acesteia din timpul utilizarii:

 http://192.168.0.1/login.php

Credentialele default vor fi admin:changeme, Este de recomandat sa fie schimbate cat mai repede. ## WIP

Un alt mod de schimbare a setarilor ar fi editarea fisierului de configurare din /etc/pi_drone.conf ## WIP 

## Licenta
[GPLv3](https://www.gnu.org/licenses/quick-guide-gplv3.html)

## REALIZAT SLABU ANDREI SI HUTU GABRIEL
