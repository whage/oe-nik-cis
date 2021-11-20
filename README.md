# My lab project presentation for Computer Integrated Surgery class at OE-NIK, 2021

Based on https://github.com/hakimel/reveal.js

# Local dev setup
docker run \
	--rm \
	--name nginx \
	-v /home/asallai/github/whage/oe-nik-cis/nginx/nginx.conf:/etc/nginx/nginx.conf:ro \
	-v /home/asallai/github/whage/oe-nik-cis:/var/www:ro \
	-p 9999:80 \
	-d \
	nginx

# Links

https://www.espressif.com/sites/default/files/documentation/esp32_technical_reference_manual_en.pdf
https://en.wikipedia.org/wiki/Bang%E2%80%93bang_control
https://en.wikipedia.org/wiki/Proportional_control
https://en.wikipedia.org/wiki/Setpoint_(control_system)
https://en.wikipedia.org/wiki/PID_controller
https://www.ni.com/hu-hu/innovations/white-papers/06/pid-theory-explained.html

# Megbeszélés Renivel - 2021.10.19.

- PID szabályozót ajánl implmentálni
- videokat érdemes megnézni róla
- fuzzy irány izgalmas terület, érdemes megnézni
- Kalman filter
	- állapotokat tud megjósolni
