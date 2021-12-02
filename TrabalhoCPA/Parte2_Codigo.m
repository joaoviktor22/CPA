%Rede de Petri
global A x0 b1 b2a b2b b2c b2d b2e b3 b4a b4b b5 b6 chavea chaveb ea eb ec ed ee reseta resetb retorno q2
A = [-1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0;1,-1, 0, 0, 0,-1, 0, 0, 0, 0, 0;0, 0,-1, 0, 0, 0,-1, 0, 0, 0, 0;0, 0,-1, 0, 0, 0, 0,-1, 0, 0, 0;0, 0, 0,-5, 0, 0, 0, 0,-5, 0, 0;0, 0, 0, 0,-1, 0, 0, 0, 0,-1, 0;0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0;0, 0,-1, 0, 0, 0,-1, 0, 0, 0, 0;0, 0,-1, 0, 0, 0, 0,-1, 0, 0, 0;0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0;0, 0, 0,-5, 1, 0, 0, 0,-5, 1, 0;0, 0, 0, 0, 0, 0,-1, 1, 0, 0, 0;0, 0, 0, 0, 0, 0, 1,-1, 0, 0, 0;0, 0, 0,-5, 0, 0, 0, 0,-5, 0, 0;0, 0, 0, 0,-1, 0, 0, 0, 0,-1, 0;0,-1, 0, 0, 0,-1, 0, 0, 0, 0, 1;0, 0,-1, 0, 0, 0,-1, 0, 0, 0, 1;0, 0,-1, 0, 0, 0, 0,-1, 0, 0, 1;0, 0, 0,-5, 0, 0, 0, 0,-5, 0, 1;0, 0, 0, 0,-1, 0, 0, 0, 0,-1, 1;1, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1];
x0 = [1,0,0,0,0,0,0,0,0,0,0];
b1 = [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
b2a = [0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];%transicoes repetidas b2
b2b = [0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
b2c = [0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
b2d = [0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
b2e = [0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
b3 = [0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
b4a = [0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0];%transicoes repetidas b4
b4b = [0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0];
b5 = [0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0];
b6 = [0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0];
chavea = [0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0];%transicoes repetidas chave
chaveb = [0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0];
reseta = [0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0];%transicoes repetidas reset
resetb = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0];
ea = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0];%transicoes repetidas e
eb = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0];
ec = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0];
ed = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0];
ee = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0];
retorno = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1];
q1 = [];
q2 = [];
N = 4;%N disparos para a parte 1
parte1(N,q1)
parte2(x0,b1)
sequencia = [b1;b3];%sequencia separada por ;linhas diferentes
estado = parte3(sequencia)
function s = check(estado,trans)%funcao que checa se a transicao esta habilitada
global A b3 b5
x = estado + (trans*A);
s = all(x >= 0);
if trans == b3
    if estado(2) == 0
        s = 0;
    end
end
if trans == b5
    if estado(3) == 0
        s = 0;
    end
end
end
function arvore(N,estado,q1)
global A b1 b2a b2b b2c b2d b2e b3 b4a b4b b5 b6 chavea chaveb ea eb ec ed ee reseta resetb retorno q2
if N == 0
    return
end
      if check(estado,b1) == 1
        x = estado + (b1*A);
        q1 = [q1 " b1"];
        q3 = strjoin(q1);
        q2 = [q2 q3];
        arvore(N-1,x,q1)
        q1(end) = [];
      end
      if check(estado,b2a) == 1
        x = estado + (b2a*A);
        q1 = [q1 " b2"];
        q3 = strjoin(q1)
        q2 = [q2 q3];
        arvore(N-1,x,q1)
        q1(end) = [];
      end
      if check(estado,b2b) == 1
        x = estado + (b2b*A);
        q1 = [q1 " b2"];
        q3 = strjoin(q1);
        q2 = [q2 q3];
        arvore(N-1,x,q1)
        q1(end) = [];
      end
      if check(estado,b2c) == 1
        x = estado + (b2c*A);
        q1 = [q1 " b2"];
        q3 = strjoin(q1);
        q2 = [q2 q3];
        arvore(N-1,x,q1)
        q1(end) = [];
      end
      if check(estado,b2d) == 1
        x = estado + (b2d*A);
        q1 = [q1 " b2"];
        q3 = strjoin(q1);
        q2 = [q2 q3];
        arvore(N-1,x,q1)
        q1(end) = [];
      end
      if check(estado,b2e) == 1
        x = estado + (b2e*A);
        q1 = [q1 " b2"];
        q3 = strjoin(q1);
        q2 = [q2 q3];
        arvore(N-1,x,q1)
        q1(end) = [];
      end
      if check(estado,b3) == 1
        x = estado + (b3*A);
        q1 = [q1 " b3"];
        q3 = strjoin(q1);
        q2 = [q2 q3];
        arvore(N-1,x,q1)
        q1(end) = [];
      end
      if check(estado,b4a) == 1
        x = estado + (b4a*A);
        q1 = [q1 " b4"];
        q3 = strjoin(q1);
        q2 = [q2 q3];
        arvore(N-1,x,q1)
        q1(end) = [];
      end
      if check(estado,b4b) == 1
        x = estado + (b4b*A);
        q1 = [q1 " b4"];
        q3 = strjoin(q1);
        q2 = [q2 q3];
        arvore(N-1,x,q1)
        q1(end) = [];
      end
      if check(estado,b5) == 1
        x = estado + (b5*A);
        q1 = [q1 " b5"];
        q3 = strjoin(q1);
        q2 = [q2 q3];
        arvore(N-1,x,q1)
        q1(end) = [];
      end
      if check(estado,b6) == 1
        x = estado + (b6*A);
        q1 = [q1 " b6"];
        q3 = strjoin(q1);
        q2 = [q2 q3];
        arvore(N-1,x,q1)
        q1(end) = [];
      end
      if check(estado,chavea) == 1
        x = estado + (chavea*A);
        q1 = [q1 " chave"];
        q3 = strjoin(q1);
        q2 = [q2 q3];
        arvore(N-1,x,q1)
        q1(end) = [];
      end
      if check(estado,chaveb) == 1
        x = estado + (chaveb*A);
        q1 = [q1 " chave"];
        q3 = strjoin(q1);
        q2 = [q2 q3];
        arvore(N-1,x,q1)
        q1(end) = [];
      end
      if check(estado,ea) == 1
        x = estado + (ea*A);
        q1 = [q1 " e"];
        q3 = strjoin(q1);
        q2 = [q2 q3];
        arvore(N-1,x,q1)
        q1(end) = [];
      end
      if check(estado,eb) == 1
        x = estado + (eb*A);
        q1 = [q1 " e"];
        q3 = strjoin(q1);
        q2 = [q2 q3];
        arvore(N-1,x,q1)
        q1(end) = [];
      end
      if check(estado,ec) == 1
        x = estado + (ec*A);
        q1 = [q1 " e"];
        q3 = strjoin(q1);
        q2 = [q2 q3];
        arvore(N-1,x,q1)
        q1(end) = [];
      end
      if check(estado,ed) == 1
        x = estado + (ed*A);
        q1 = [q1 " e"];
        q3 = strjoin(q1);
        q2 = [q2 q3];
        arvore(N-1,x,q1)
        q1(end) = [];
      end
      if check(estado,ee) == 1
        x = estado + (ee*A);
        q1 = [q1 " e"];
        q3 = strjoin(q1);
        q2 = [q2 q3];
        arvore(N-1,x,q1)
        q1(end) = [];
      end
      if check(estado,reseta) == 1
        x = estado + (reseta*A);
        q1 = [q1 " reset"];
        q3 = strjoin(q1);
        q2 = [q2 q3];
        arvore(N-1,x,q1)
        q1(end) = [];
      end
      if check(estado,resetb) == 1
        x = estado + (resetb*A);
        q1 = [q1 " reset"];
        q3 = strjoin(q1);
        q2 = [q2 q3];
        arvore(N-1,x,q1)
        q1(end) = [];
      end
      if check(estado,retorno) == 1
        x = estado + (retorno*A);
        q1 = [q1 " retorno"];
        q3 = strjoin(q1);
        q2 = [q2 q3];
        arvore(N-1,x,q1)
        q1(end) = [];
      end
end%fornece todas as sequencias possiveis
function parte1(N,q1)
global x0 q2
arvore(N,x0,q1);
q2 = unique(q2)
end%parte1,fornece todas as sequencias possiveis
function parte2(estado,trans)
s = check(estado,trans)
end%parte2,chega se a transicao esta habilitada
function estado = parte3(seq)
global x0 A
estado = x0;
[linha,coluna] = size(seq);
for i = 1:linha
    if check(estado,seq(i,:)) == 1
        estado = estado + (seq(i,:)*A);
    else
        estado = ["Sequencia Invalida"];
    return
    end
end
end%parte3,retorna estado apos sequencias