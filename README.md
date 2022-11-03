# poo-ufmg
Disicplina de Programação Orientada a Objeto da Escola de Engenharia da UFMG

# 🚀 Como compilar e executar
## 🐧 - No Linux/WSL:
Clone o repositório no VS Code ou no seu editor de código preferido como na imagem abaixo:

![clonar repositorio](https://user-images.githubusercontent.com/97178655/192149111-17b9a555-15c5-4021-b1d5-503ea1e12ecc.png)

Se vc ainda não tiver uma pasta "build" criada junto com as pastas do projeto, crie-a para que a compilação de certo, sendo que não é necessário adicionar nenhum arquivo na pasta.
Depois, de o comando "make" para compilar todos os arquivos, como mostrado na imagem abaixo!

![comocompilar](https://user-images.githubusercontent.com/97178655/192149932-4c46a641-ad5d-4d08-b20e-72ca33273801.png)

Agora, de o comando "./main" para executar o arquivo "main" que foi gerado. Depois disso, o programa estará rodando :)

![executaromain](https://user-images.githubusercontent.com/97178655/192150184-d1512160-ec59-4e8b-b791-c01f010752d2.png)
### Atenção: caso queria upar alguma melhoria no código e/ou sugestão para o Github do projeto, não se esqueça de dar o comando "make clean" no terminal para limpar os arquivos ".d" e ".o" criados!

## 👻 - No Windows:
Repita os mesmos passos que estão descritos para o Linux/WSL e não se esqueça de criar a pasta "build" também, caso ainda não possua ela.
As únicas diferenças para o processo de compilação são: 
### 1 - ao invés do comando "make", de o comando "mingw32-make"
### 2 - ao invés do comando "make clean", de o comando "mingw32-make cleanw" no terminal para limpar os arquivos ".d" e ".o" criados
O comando "./main" para executar o arquivo principal permanece igual para ambos os sistemas operacionais.


# Como executar os testes?

### 1 - Rodar o Script na pasta ./tests/scripts
### 2 - Rodar o teste gerado na pasta ./tests/executaveis

### EXEMPLO com a classe Cliente 
Na pasta do projeto execute o seguinte comando no terminal 
#### ./tests/scripts/testaCliente
posteriormente, o seguinte comando
#### ./tests/executaveis/testCliente


# Como Instanciar a classe Empresa, logar um Usuário e permitir a usabilidade de funções a esse Usuário?

### 1 - #includes
#### #include "../include/Empresa.h"
#### #include "../include/Usuario.h"

### 2 - Criação de Usuário
##### Usuario *user = new Usuario("emailDoUsuario@gmail.com", "senhaDoUsuario");

### 3 - Setar as permissões disponíveis para tal usuário

####  vector<string> permissoes;
####  permissoes.push_back("Permissao1");
####  permissoes.push_back("Permissao2");
####  permissoes.push_back("Permissao3"); e etc ...

Quando terminar de colocar todas as permissões precisa setar as permissões

#### user->setPermissoes(permissoes);

### 4 - Instanciar a Empresa;
#### Empresa *empresa = Empresa::getEmpresa();
Note que não precisa de permissão para instanciar a empresa, pois não tem coerência em permitir ou não acesso sem antes logar com um usuário

### 5 - Logar o usuário na Empresa;
#### empresa->login(user);


# Relação de Testes já feitos.

#### |      CLASSES     | TESTES |
#### |     Empresa      |   ✅   |
#### |     Pessoa       |   ✅   |
#### |      Cargo       |   ✅   |
#### |   Departamento   |   ✅   |
#### |     Cliente      |   ✅   |
#### |       Lote       |   ✅   |
#### |       data       |   ✅   |
#### |     Usuario      |   ✅   |
#### |     Salario      |   ✅   |
#### |    Categoria     |   ✅   |
#### |  OrdemDeProducao |   ❌   |
#### |      Produto     |   ❌   |
#### |  RegistroVendas  |   ❌   |
#### |       Log        |   ✅   |
#### |    LogEscrita    |   ❌   |
#### |    LogLeitura    |   ❌   |

# Link para o UML

https://lucid.app/lucidspark/644ed113-c0ac-4b7a-b117-c59e523f0f19/edit?beaconFlowId=A80BDD8C84EAD321&invitationId=inv_385cb980-e430-4cf0-8917-3605c53333be#