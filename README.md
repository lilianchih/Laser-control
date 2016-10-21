This program is written for the “Photon” device (https://www.particle.io/products/hardware/photon-wifi-dev-kit). I use this device to control and coordinate my laser system in testing phase.

A digital output pin gives triggers to the RF driver so that its frequency jumps to the next step. A digital-to-analog output is used to control the current value of the laser diode controller. 

The laser we are controlling here is a slave laser, receiving light that comes from a master laser and passes through an Electro-Optical Modulator (driven by RF), which shifts the input frequency. The intrinsic frequency of the slave laser should be close enough to the frequency of the injection beam to follow it well. Therefore, every time the frequency of the injection beam changes, the current, which is related to the slave laser intrinsic frequency, changes accordingly.