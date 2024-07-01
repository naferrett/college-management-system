# Projeto: College Management System

Código do projeto final da matéria Programação Orientada à Objetos (SI300B) da UNICAMP.

![image](https://github.com/naferrett/college-management-system/assets/133066462/666b1dd8-5568-463f-92c2-73fd3948ae38)


## 🎯 Objetivo

Desenvolver um sistema de gerenciamento escolar em C++ para agregar os conteúdos previstos para a disciplina.
- A interface de usuário será em língua portuguesa, mas, para consistência de nomenclatura, todo o código interno deverá ser escrito em inglês. 

## ⚙️ Fluxo do Programa

Quando o programa é iniciado, o usuário é apresentado ao Menu Principal, que contém as seguintes opções:
1. Estudantes: Ao selecionar esta opção, o usuário é levado ao submenu de estudantes, onde pode realizar ações como inserir novos estudantes, visualizar todos os estudantes, pesquisar estudantes por RA, alterar e remover estudantes.
2. Professores: Ao escolher esta opção, o usuário é direcionado ao submenu de professores, onde pode gerenciar informações relacionadas aos professores, como adicionar novos professores, visualizar a lista de professores, etc.
3. Turmas: Esta opção leva o usuário ao submenu de disciplinas, onde ele pode adicionar novas disciplinas, visualizar as disciplinas existentes, associar professores e estudantes às disciplinas, entre outras ações.
4. Relatórios: Ao selecionar esta opção, o usuário é levado ao submenu de relatórios.
5. Ajuda: Esta opção fornece informações sobre o sistema.
6. Sair do programa: Ao escolher esta opção, o programa é encerrado

## 🏗️ Estrutura

O projeto deve seguir a seguinte estrutura de diretórios:
```
projeto/
│
├── include/
│ ├── dto/
│ ├── dao/
│ ├── menu/
│ ├── system/
│ ├── utils/
│ ├── database/
│
├── src/
│ ├── dto/
│ ├── dao/
│ ├── menu/
│ ├── system/
│ ├── utils/
│ ├── database/
│ ├── Start.cpp
│
├── shell.txt
```

- A pasta <i>include</i> deve conter todos os arquivos de cabeçalhos (.h) e a pasta <i>src</i> deve conter todos os arquivos de implementação (.cpp).
- O arquivo <i>shell.txt</i> é um arquivo que contém a linha de comando para compilar e executar o programa usando o compilador g++.

## 👨‍💻 Clonando o projeto

Para instalar o projeto:

```
git clone https://github.com/naferrett/college-management-system.git
```

## ☕ Usando o projeto

Para usar o projeto, siga estas etapas:

1. Compile o projeto com a linha de comando abaixo:

```
g++ -o projeto src/dao/ClassDAO.cpp src/dao/StudentDAO.cpp src/dao/TeacherDAO.cpp src/dto/ClassDTO.cpp src/dto/Person.cpp src/dto/Semester.cpp src/dto/StudentDTO.cpp src/dto/Subject.cpp src/dto/TeacherDTO.cpp src/dto/SemesterSubject.cpp src/menu/Menu.cpp src/system/SysInfo.cpp src/utils/Utils.cpp src/database/College.cpp src/database/Controller.cpp src/Start.cpp
```

2. Execute o projeto com a linha de comando abaixo:

```
./projeto
```
