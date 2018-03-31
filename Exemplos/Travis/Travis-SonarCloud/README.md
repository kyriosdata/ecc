# Sobre o exemplo
O objetivo desse exemplo é apresentar a adição da ferramenta SonarCloud e como realizar a chamada da análise através do script .travis.yml.

# Sobre os comandos no Script

* Para adicionar a ferramenta: 
       
       addons:
          sonarcloud:
             organization: "kyriosdata-github" 
             token: $SONAR_TOKEN               

* Para ativar a análise estática:

        script:
          - sonar-scanner

**Notas:** 

A etapa addon deve ser feita após a definição das variáveis de ambiente, por exemplo, compilador, e antes da primeira etapa de
build.

O token informado já deve ter sido definido. Consulte a [wiki](https://github.com/kyriosdata/ecc/wiki/SonarCloud#primeiros-passos) para 
saber mais.

Um arquivo chamado 'sonar-project.properties' já deve ter sido criado para que a ferramenta execute corretamente.
