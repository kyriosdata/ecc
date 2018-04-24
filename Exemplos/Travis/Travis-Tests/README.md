# Sobre o exemplo
O objetivo desse exemplo é apresentar a forma de se fazer uso da CTest que faz parte do pacote CMake. Trata-se de um gerenciador de testes que
usa basicamente o mesmo formato de comandos de CMake.

Um objetivo secundário desse exemplo é fornecer ao SonarCloud um conjunto de testes sob funções para verificar a cobertura dos mesmos.

# Sobre os comandos no Script

* Para executar o script de testes:

        script:
		  - build-wrapper-linux-x86-64 --out-dir bw-output make
		  - ctest -V
O comando build-wrapper faz parte do uso do SonarCloud. Ele serve para empacotar a saída da build para que a ferramenta SonarCloud possa analisá-la. 
Após a construção do exemplo, é possível executar o comando cteste. Esse comando ativa o script [CMakeLists.txt](https://github.com/kyriosdata/ecc/blob/master/Exemplos/CMake/CMake-Tests/tests/CMakeLists.txt)
