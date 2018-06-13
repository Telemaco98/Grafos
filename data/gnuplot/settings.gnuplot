# Inicialização
clear
reset
set key on

# Configurações de saída: inclui formato de exportação, tamanho do gráfico,
# fontes utilizadas e nome do arquivo de saída

# Exportação para o formato .png
# set terminal png size 1366 768 enhanced font 'Helvetica,12'
# set out '../images/EmpiricalAnalisysResult.png'
set output './data/images/EmpiricalAnalisysResult.png'

# Configuração do eixo horizontal
#set xrange[2:1024]					# Faixa de valores dos tamanhos dos grafos
# Salto entre valores
set xtic rotate by -90 scale 0		# Rotação dos rótulos
set xlabel "Tamanho do Grafo (qtd. de nós)"

# Título do gráfico 
set title 'Tempos de execuções dos algoritmos de caminho mais curto'

# Configuração do eixo vertical
# set yrange[0:0.00001]				# Faixa de valores dos tempos
set ylabel "Tempo (em milliseconds)"
# set format y "%.2f"

# Plotagem do gráfico
# Os dados a serem plotados constam no arquivo times.dat
plot './data/output/times.dat' using 1:2 lw 2 with lines title "Dijstra"
#, './data/output/times.dat' u 1:3 lw 2 with lines title "Decimal Sort"