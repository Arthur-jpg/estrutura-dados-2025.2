from matplotlib.pyplot import grid,legend,xlabel,ylabel,plot
from math import sin,cos,factorial

xinicial = float(input("Digite o ponto inicial da série: "))
xfinal = float(input("Digite o ponto final da série: "))
termos = int(input("Digite a quantidade de termos: "))

aprox_taylor = 0
for i in range (termos):
  # No cáculo da derivada, temos um ciclo de tamanho 4, então podemos usar a ideia do resto (%) para facilitar o cálculo
  if i%4==0: 
    derivada = cos(xinicial)
  elif i%4==1:
    derivada = -sin(xinicial)
  elif i%4==2:
    derivada = -cos(xinicial)
  elif i%4 == 3:
    derivada = sin(xinicial)

  #Cálculo da série de Taylor de acordo com a quantidade de termos
  calculo_taylor = (derivada*(xfinal-xinicial)**(i)) / factorial(i)
  aprox_taylor+=calculo_taylor

print(f"Resultado da série de Taylor: {aprox_taylor}")
erro_relativo = abs(((cos(xfinal) - aprox_taylor)/cos(xfinal))*100)
print(f"Erro relativo: {erro_relativo:.2f}%")

plot(xinicial,cos(xinicial),"ro",label="ponto inicial")
plot(xfinal,cos(xfinal),"bd", label="ponto final")

plot(xfinal,aprox_taylor,"yx",label="Taylor")

grid()
legend()
xlabel("x")
ylabel("f(x)")