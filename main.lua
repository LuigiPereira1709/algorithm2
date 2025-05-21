--[[Setup]]
local nomes = {["CARREFOUR"]=1, ["GUANABARA"]=2, ["MUNDIAL"]=3, ["PREZUNIC"]=4}
local produtos = {["ARROZ"]=1, ["FEIJAO"]=2, ["AÇUCAR"]=3, ["OLEO"]=4, ["CAFE"]=5, ["FEIJÃO"]=2,["ÓLEO"]=4,  ["CAFÉ"]=5}
local mediaResultado = {}
local somaResultado = {}
local melhorParaComprar = {}

local mercados = {
	{5.10, 4.98, 5.00, 5.80, 23.12},
	{4.98, 4.89, 5.10, 6.22, 23.10},
	{5.02, 5.10, 4.98, 6.10, 23.04},
	{4.87, 4.90, 4.80, 5.98, 23.16}
}

function pesquiseMercado(Pesquisa)
	if type(Pesquisa) == "string" then
		Pesquisa = nomes[string.upper(Pesquisa)]
	end
	return Pesquisa
end

function pesquiseProduto(Pesquisa)
	if type(Pesquisa) == "string" then
		Pesquisa = produtos[string.upper(Pesquisa)]
	end
	return Pesquisa
end

function printar(tab)
	if type(tab) ~= "table" then return end
	
	for Index = 1, #tab, 1 do
		print(tab[Index])
	end
    print("-----")
end

--[[Média]]
for ProdLoop = 1, 5, 1 do
	local Media = 0
	
	for MercLoop = 1, 4, 1 do
		Media = Media + mercados[MercLoop][ProdLoop]
	end
	
	Media = Media/4
	
	mediaResultado[ProdLoop] = Media
end

printar(mediaResultado)

--[[Soma]]
for MercLoop = 1, 4, 1 do
	local Soma = 0
	
	for ProdLoop = 1, 5, 1 do
		Soma = Soma + mercados[MercLoop][ProdLoop]
	end
	
	somaResultado[MercLoop] = Soma
end

printar(somaResultado)

--[[Melhor]]
for ProdLoop = 1, 5, 1 do
	local MenorValor = mercados[1][ProdLoop]
	melhorParaComprar[ProdLoop] = 1
	
	for MercLoop = 2, 4, 1 do
		if mercados[MercLoop][ProdLoop] < MenorValor then
			MenorValor = mercados[MercLoop][ProdLoop]
			melhorParaComprar[ProdLoop] = MercLoop
		end
	end
end

printar(melhorParaComprar)
