# Sobre o exemplo
O objetivo desse exemplo é apresentar uma versão simples do script .travis.yml para compilar e executar um programa simples escrito em C .

# Sobre os comandos no Script

* Selecionar a linguagem do projeto. Basta adicionar a seguinte linha no topo do script:

          language: C
 
* Selecionar o compilador. Basta adicionar o seguinte após a definição da linguagem, mas antes de qualquer outra etapa:

          compiler:
             - gcc
           
 Observe que o comando poderia ter sido feito em apenas uma linha, como no comando para definir a linguagem. Para projetos em C sendo 
 executados em uma máquina virtual Ubuntu, em que o compilador especificado gcc já se encontra instalado por padrão, podemos fazer isso 
 sem maiores preocupações.
 
 * Etapas - O script .travis.yml permite separar os comandos a serem executados por etapas. Neste exemplo, apresento duas delas, 
 before_script e script, todos os comandos presentes nessas duas etapas podem ser interpretados, já que são comandos reconhecidos pela 
 shell do Ubuntu.
 
 * before_script - Nesse exemplo, antes que o script para compilação e execução do exemplo posssa ser executado, o diretório que contém o 
 arquivo deve ser acessado. Esse é o papel do comando escrito na etapa before_script nesse exemplo.
 
           before_script:
              - cd Exemplos/Travis/Travis-Basic
            
* script - Nessa etapa, o código-fonte main.c é compilado, um executável é criado e em seguida executado. Observe que são múltiplos 
comandos para a mesma etapa. Cada um desses comandos retorna uma saída 0 ou 1, sucesso ou falha, e a etapa só é considerada um sucesso 
caso todos eles tenham tido saída 0. 

          script:
             - gcc -c main.c
             - gcc main.o -o exec
             - ./exec


      


