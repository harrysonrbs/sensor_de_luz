    # sensor_de_luz - Objetos Inteligentes Conectados

    Abstract. 

The Light Sensor is a basically simple project, however, intelligent and quite intuitive that looks like something magical. Very similar to streetlights that turn on by themselves when dark, this project uses a primordial component, the LDR, that is, a light-dependent resistor which will be activated when your environment lacks lighting. This project can be very useful for energy savings, so its operation is evident when there is a dependence on lighting necessary to perform any basic tasks in certain environments.

    Resumo. 

O Sensor de Luz é um projeto basicamente simples, porém, inteligente e bastante intuitivo que parece algo mágico. Bem semelhante as luzes de postes que acendem sozinhas ao escurecer, este projeto utiliza de um componente primordial, o LDR, ou seja, um resistor dependente de luz o qual será acionado quando seu ambiente faltar iluminação. Este projeto pode ser bastante útil para economia de energia, logo seu funcionamento é evidente quando há uma dependência de iluminação necessária para a execução de quaisquer tarefas básicas em determinados ambientes.

    Projeto.

Neste Projeto será utilizado a placa de desenvolvimento que combina o chip ESP8266, uma interface usb-serial e um regulador de tensão 3.3V. A programação pode ser feita usando LUA ou a IDE do Arduino, utilizando a comunicação via cabo microusb. Abaixo, algumas informações curiosas sobre o componente.

“NodeMCU é um firmware de código aberto, para o qual projetos abertos de placas de prototipação estão disponíveis. O nome ‘NodeMCU’ combina as palavras em inglês "node" (Nó) e ‘MCU’ (Acrônimo para microcontrolador).[6] O termo ‘NodeMCU’ se refere estritamente ao firmware, e não aos kits de desenvolvimento associados. O firmware usa a linguagem de script Lua.[7] Baseado no projeto e Lua, foi construído sobre o SDK ESP8266 0.9.5. Existem muitos projetos de código aberto para o seu uso como a lua-cjson e SPIFFS” (WIKIPEDIA, 2022).

    Materiais necessários.

Módulo Sensor de Luz – LDR;
5 Fios Jumper’s;
Protoboard;
NodeMCU ESP8266 ou similar;
LED;
2 Resistores 330Ohm.

É possível realizar a programação da placa NodeMCU com chipset WiFi embutido através da sua Arduino IDE utilizando a própria linguagem do Arduino. Antes de prosseguir com esse experimento é importante que você tenha a Arduino IDE instalada em seu computador. Além disso você também precisará que os drivers da sua placa estejam instalados.

    Comunicação.

Será utilizado o protocolo MQTT em ambiente público, on-line e gratuito e um cliente HiveMQ MQTT WebSocket para facilitar a experiência com mensagens MQTT conforme Figura 10. MQTT que é um protocolo mais leve que o HTPP e foi pensado justamente para funcionar em sistemas de Internet das Coisas. Ele possui uma arquitetura de publicação/assinatura que é controlado por um Broker MQTT conforme Figura 11, que faz o elo entre as publicações e os clientes.


