# Sobre o exemplo
O objetivo desse exemplo é apresentar uma versão simples do script .travis.yml que faça uso do CMake para criar o makefile a ser usado 
na compilação dos fontes.

# Sobre os comandos no Script

* Criar a pasta build e executar o CMake:

          before_script:
            - cd Exemplos/CMake/CMake-Configure
            - mkdir build
            - cd build
            - cmake ..

Nessa etapa se cria o diretório build que receberá os binários resultantes da execução do CMake, e o executável após a execução do make 
na etapa 'script'. O comando cmake recebeu como argumento o diretório raiz do atual pois é nele que se encontra o arquivo CMakeLists.txt
principal.

* after_script - Nessa etapa, o código-fonte já foi compilado e o executável já foi criado e colocado na pasta build/bin. Portanto ele 
já pode ser executado. 

          after_script:
             - cd bin
             - ./sistema

