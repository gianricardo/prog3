
Para compilar o programa pode-se usar o arquivo .pro do diretorio PacienciaSpyder ou do diretorio base

Procedimento para compilar e rodar o programa no diretorio base:

	$ qmake PROJECT=PacienciaSpyder
	$ make run

Procedimento para compilar e rodar o programa no diretorio PacienciaSpyder:

	$ qmake
	$ make
	$ ./PacienciaSpyder



	Ao compilar pelo diretorio base os arquivos do "carteado" serão recompilador, enquanto que pelo diretorio do projeto é
utilizado uma biblioteca estatica para linkar com os arquivos fonte do "carteado", para gerar o arquivo da biblioteca estatica
deve-se seguir esses passos, a partir do diretorio base:

	$ ./stlb.sh
	$ mv libcarteado.a PacienciaSpyder


