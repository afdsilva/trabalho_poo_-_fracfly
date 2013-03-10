trabalho_poo_-_fracfly
======================

Trabalho POO – FracFly:
Integrantes:
André Felipe da Silva – 11107587
Eliézer Ribeiro
Mário Saldanha
Lúcio Leal Bastos

Documentação:


Desenvolvedor:


Fluxo de execução: Através da classe FracFly, é criado um objeto oJogo, a classe FracFly, possui o seguinte fluxo:
	NoInic: Inicializa bibliotecas do SDL, como SDL_Init e SDL_TTF e inicializa variáveis que necessitam ser inicializadas antes da criação do plano de exibição; 

	NoEvento: Controla os eventos de entrada (como teclado, mouse, joystick), possui métodos virtuais que devem ser implementados para cada estado;

	NoLaco: Controla a alteração de dados das entidades;

	NaRenderizacao: Agrega ao plano de exibição todas camadas pertencente a entidades.

	NaLimpeza: Coletor de lixo, limpa superfícies (SDL);


Criação de Entidade:
	FEntidade: Cria uma entidade genérica, possui atributos necessários para criar um objeto com suporte a movimento, colisao, carregamento de um recurso de imagem;
	FEntidadeTexto: Cria uma entidade de texto básica, alem dos recursos basicos de uma entidade permite carregar um recurso ou um arquivo de fonte;
	FEntidadeBotao: Entidade com atributos e metodos para funcionar como um botao, como “hover” (Metodo AoPassarPorCima ), e clique (AoClicarDireito/ AoClicarEsquerdo), através da colisão com o mouse;
	
Controle de Colisão: Toda entidade quando se move (por causa de algum evento) tem chance de colidir com outro objeto, a entidade tem capacidade de verificar a sua posição com a do objeto colidido e tomar ações de acordo com a entidade;

Tratamento de Exceção: Através da classe Exceçoes, os atributos estáticos msgErro, classErro e linhaErro, geram na saída padrão mensagens de erro formatas (eventualmente pode ser considerado a criação de uma janela “modal” no próprio jogo informando o erro;




Usuário:

Inicio:

Opções:

Sair:





Créditos:

Engine: SDL – http://www.libsdl.org/
Framework: SDL Tutorials – http://www.sdltutorials.com/
Imagens: Lúcio (cockpit, tiro, canhoes, efeitos de luz), google imagens
Fontes: http://www.netfontes.com.br/ 
Referencias, exemplos e tudo mais: google

Agradecimentos:
Prof. Gerson Cavalheiro – Por nos dar oportunidade de fazer um trabalho do tipo.
SDL Tutorials – Por criar tutoriais explicando – muito bem – o funcionamento básico de um framework voltado para jogos e sobre SDL.
