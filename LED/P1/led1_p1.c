echo "led 1 (RUN)  Pattern 1"
echo "if want end: ctrl + c"

for((;;));
do
  echo 1 > /sys/class/gpio/gpio491/value
  sleep 0.4s
  echo 0 > /sys/class/gpio/gpio491/value
  sleep 0.3s
  echo 1 > /sys/class/gpio/gpio491/value
  sleep 0.3s
  echo 0 > /sys/class/gpio/gpio491/value
  sleep 0.2s
  echo 1 > /sys/class/gpio/gpio491/value
  sleep 0.2s
  echo 0 > /sys/class/gpio/gpio491/value
  sleep 0.1s
  echo 1 > /sys/class/gpio/gpio491/value
  sleep 0.1s
  echo 0 > /sys/class/gpio/gpio491/value
  sleep 0.1s
  echo 1 > /sys/class/gpio/gpio491/value
  sleep 0.2s
  echo 0 > /sys/class/gpio/gpio491/value
  sleep 0.2s
  echo 1 > /sys/class/gpio/gpio491/value
  sleep 0.3s
  echo 0 > /sys/class/gpio/gpio491/value
  sleep 0.2s
  echo 1 > /sys/class/gpio/gpio491/value
  sleep 0.4s
done