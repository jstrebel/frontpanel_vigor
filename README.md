# vigor frontpanel mit Folientastatur.

Bedienung:  Entwurf der das Bedieninterface der Kotrollerbox erklärt

Schemas:  

Testcode:     Beispiel lesen der Tastatur input mit dem Arduino

TFT display:  Für die Anzeigen wird ein gut Dokumentierte Library verwendet.
Doku auf: https://github.com/gavinlyonsrepo/Display_Lib_RPI

Das ist der Code welcher der Entwickler für mich machte. 
Dieser Code ist mit dem Raspi 4 getestet.
https://github.com/gavinlyonsrepo/ST7789_TFT_RPI/releases

Gavin hat die Beschreibung upgedatet, Grund war, dass der code den wir verwenden eine andere Library verwendet.
https://github.com/gavinlyonsrepo/ST7789_TFT_RPI

BEM: werde dieses Repository weiter organisieren und aufräumen 



## Installationen im Raspi

### bcm2835
```
curl -sL http://www.airspayce.com/mikem/bcm2835/bcm2835-1.75.tar.gz | tar xz
./configure
make
sudo make check
sudo make install
```

### redis 
https://fleetstack.io/blog/redis-on-raspberry-pi-setup
```
sudo apt install redis-server -y
```

Falls wenig RAM Memorybegrenzung:
```
sudo nano /etc/redis/redis.conf
maxmemory 100mb maxmemory-policy allkeys-lru
```

Hinzufügen zum Autostart und starten von redis 
```
sudo systemctl  enable  redis-server
sudo systemctl start redis-server
```

Testen:
```
redis-cli
set  testkey  "hello"
get testkey
```

### hiredis
```
sudo apt-get install libhiredis-dev
```
