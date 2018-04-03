# Sobre o exemplo
O objetivo desse exemplo é apenas fornecer o arquivo sonar-project.properties a ser usado no exemplo de uso da ferramenta SonarCloud.

O comando 
       
    - sonar.cfamily.build-wrapper-output=build/bw-output


está diretamente relacionado com o comando 
          
   
    - build-wrapper-linux-x86-64 --out-dir bw-output make
    

na etapa de script do arquivo .travis.yml. Ele é necessário para que a ferramenta SonarCloud encontre o arquivo bw-output no path correto

**Notas:** 

Parte dos metadados configurados pode precisar ser trocada pelos nomes corretos.

Para uso do exemplo, esse arquivo deve ser incluído na raiz do repositório.
