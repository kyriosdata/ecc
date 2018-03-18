# Sobre o exemplo
O objetivo desse exemplo é apresentar a forma de se fazer uso da função install de CMake que cria uma regra de instalação para um projeto. 
Nesse caso especificamente, uma regra para definir a instalação de uma target biblioteca, um arquivo e um executável. 

# Sobre os comandos no Script

* Para executar a compilação da instalação:

        script:
          - make
          - sudo make install

O comando make install deve ser precidido de sudo por critérios da máquina virtual fornecida pelo Travis. Após esse comando é possível 
acessar o diretório /Exemplos/CMake/CMake-Install-Use/lib e observar os novos arquivos.
