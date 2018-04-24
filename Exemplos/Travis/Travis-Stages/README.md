# Sobre o exemplo
O objetivo desse exemplo é apresentar uma nova forma de dividir os estágios da build. Com essa organização, Travis interpreta a build como estágios.
Cada estágio de build pode ter uma saída zero ou não zero. Se alguma das saídas de estágio é um não-zero, toda a build falha.


Essa organização permite dividir o processo de build em estágios que possuam tarefas específicas. Isso também permite que adaptemos o fluxo da build
da forma mais adequada à lógica do projeto. Por exemplo, se desejamos que binário resultante só seja empacotado após todos os testes sobre ele terem
tido sucesso, podemos adicionar um estágio "Tests" antes do estágio "Package".

# Sobre os comandos no Script

* Para dividir as etapas da build:

        jobs:
			include:
			- stage: nome do estágio
			  script:
				- comandos da etapa script

			- stage: outro estágio
			  script:
				- novo comando de script


No exemplo, temos:

		before_script:
		  - cd Exemplos/CMake/CMake-Tests
		  - mkdir build
		  - cd build
		  - cmake ..

		jobs:
			include:
			- stage: build and sonar
			  script:
				- build-wrapper-linux-x86-64 --out-dir bw-output make        
				- cd ../../../..
				- sonar-scanner

			- stage: tests
			  script:
				- make
			  after_script:
				- ctest -V


Como o comando ctest -V foi adicionado na etapa after_script do estágio tests, sua saída só fará com que a epata, 
e consequentemente a build, falhe se ela for um timeout.

Etapas específicadas fora do escopo de jobs, como before_script no exemplo, são executadas para todas as etapas.