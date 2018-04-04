# Sobre o exemplo
O objetivo desse exemplo é apresentar a adição da ferramenta SonarCloud e como realizar a chamada da análise através do script .travis.yml.

## Sobre os comandos no Script

* Para adicionar a ferramenta: 
       
       addons:
          sonarcloud:
             organization: "kyriosdata-github" 
             token: $SONAR_TOKEN               

* Para ativar a análise estática:

        script:
          - sonar-scanner
          
## Como Adicionar uma badge

É possível adicionar uma badge para mostrar o resultado da análise de qualidade feita pela ferramenta no README do projeto. Para isso, siga os seguintes passos:

1. Acesse a [dashboard do projeto](https://sonarcloud.io/dashboard?id=ecc) pela URL https://sonarcloud.io/dashboard?id=<id_do_projeto>
2. Clique em Get Project Badges como na imagem

![](https://i.imgur.com/fKiOkud.png)

3. Em seguida, na nova tela, selecione o estilo da badge e a métrica desejada. 

![](https://i.imgur.com/UXW2SbN.png)

4. Copie o texto gerado clicando em copy na mesma tela.

5. Dentro do README onde se deseja expor a badge inclua:

       ![Quality Gate](<texto_copiado>)
     
6. O resultado é algo do tipo: 

![Quality Gate](https://sonarcloud.io/api/project_badges/measure?project=ecc&metric=alert_status)

**Notas:** 

A etapa addon deve ser feita após a definição das variáveis de ambiente, por exemplo, compilador, e antes da primeira etapa de
build.

O token informado já deve ter sido definido. Consulte a [wiki](https://github.com/kyriosdata/ecc/wiki/SonarCloud#primeiros-passos) para 
saber mais.

Um arquivo chamado 'sonar-project.properties' já deve ter sido criado para que a ferramenta execute corretamente.
