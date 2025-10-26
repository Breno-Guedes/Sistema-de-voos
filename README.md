# ✈️ Sistema de Reservas de Voos em C  

**Curso:** Análise e Desenvolvimento de Sistemas  
**Período:** Módulo 1  

---

## 🎯 Objetivo do Sistema  

Criar um sistema simples para **cadastrar voos**, **pesquisar voos**, **fazer reservas** e **exibir reservas**. O sistema é desenvolvido em **linguagem C**, com interação feita pelo **terminal**. Os dados são armazenados **apenas na memória** enquanto o programa está em execução.  

---

## 🗂️ Arquivos do Projeto  

- **reserva.h** → Cabeçalho com as estruturas e declarações das funções.  
- **reserva.c** → Implementação das funções principais do sistema.  
- **main.c** → Função principal (menu) que chama as demais funções.  

---

## 🧩 Structs Utilizadas  

### ✈️ Voo  
Guarda os dados principais de um voo:  
- Número do voo  
- Origem  
- Destino  
- Data  
- Hora de partida  
- Hora de chegada  

### 🧳 Reserva  
Guarda os dados de uma reserva:  
- Número do voo reservado  
- Nome do passageiro  
- Documento (RG ou passaporte)  
- Assento reservado  

---

## ⚙️ Funcionalidades do Sistema  

### 1. Cadastrar Voo  
- Solicita os dados de um novo voo (origem, destino, data, etc.).  
- Salva o voo na lista de voos.  

### 2. Exibir Todos os Voos  
- Mostra todos os voos cadastrados até o momento.  

### 3. Pesquisar Voos  
- Usuário informa origem, destino e data.  
- O sistema busca voos que correspondem exatamente às informações.  
- Caso algum campo esteja vazio, o sistema alerta que todos são obrigatórios.  

### 4. Fazer Reserva  
- Solicita número do voo, nome, documento e assento.  
- Verifica se o voo existe e se os campos obrigatórios foram preenchidos.  
- Impede reservas duplicadas no mesmo assento ou voo.  
- Garante o limite máximo de **120 assentos** por voo.  
- Se tudo estiver correto, salva a reserva.  

### 5. Exibir Reservas  
- Mostra todas as reservas registradas até o momento.  

---

## 🧠 Como Funciona o Programa (main.c)  

- Exibe um **menu** com as opções disponíveis.  
- O usuário escolhe a opção digitando o número correspondente.  
- O programa executa a função apropriada.  
- O menu é exibido novamente até o usuário optar por **sair**.  

---

## ✅ Validações Importantes  

- Impede o cadastro de voos ou reservas além do limite máximo.  
- Bloqueia pesquisa de voos sem preencher origem, destino e data.  
- Impede reserva de assento já ocupado no mesmo voo.  
- Evita reserva duplicada para o mesmo passageiro e voo.  
- Respeita o limite de **120 assentos** por voo.  

---

## 💡 Observações Finais  

- O sistema funciona **somente no terminal**.  
- Os dados **não são persistidos** (são perdidos ao encerrar o programa).  
- O código está **comentado** para facilitar o entendimento e estudo.  

---

## 👨‍💻 Desenvolvido por  

**Breno de Souza Guedes**  
Estudante do Instituto Federal do Piauí – Campus Corrente (IFPI Corrente)