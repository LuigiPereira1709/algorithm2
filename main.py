from typing import Union

# Matriz contendo os preços dos produtos em diferentes supermercados
superMarket: list[list[Union[str, float]]] = [
    ["SuperMarket", "Rice", "Bean", "Sugar", "Oil", "Coffee"],
    ["Carrefour", 5.10, 4.98, 5.00, 5.80, 23.12],
    ["Guanabara", 4.98, 4.89, 5.10, 6.22, 23.10],
    ["Mundial", 5.02, 5.10, 4.98, 6.10, 23.04],
    ["Prezunic", 4.87, 4.90, 4.80, 5.98, 23.16]
]

# Separação de cabeçalho e dados para facilitar o processamento
header: list[str] = [str(item) for item in superMarket[0]]
data: list[list[Union[str, float]]] = superMarket[1:]

def avgProductsPrice() -> list[Union[str, float]]:
    """
    Calcula o preço médio de cada produto entre todos os supermercados.

    Returns:
        list contendo a string "Average" seguida das médias dos produtos.
    """
    avgPrice: list[float] = []

    # Itera por cada coluna de produto (ignorando o nome do supermercado)
    for col in range(1, len(header)):
        prices = [float(row[col]) for row in data]
        avgPrice.append(sum(prices) / len(prices))

    return ["Average", *avgPrice]


def basicFoodBasketPerSuperMarket() -> list[Union[str, float]]:
    """
    Calcula o custo total da cesta básica (todos os produtos) por supermercado.

    Returns:
        list contendo a string "Sum" seguida do total por supermercado.
    """
    sumBasicFoodBasket: list[float] = []

    # Para cada supermercado, soma os preços dos produtos
    for row in data:
        prices: list[float] = [float(row[i]) for i in range(1, len(header))]
        sumBasicFoodBasket.append(sum(prices))

    return ["Sum", *sumBasicFoodBasket]


def appendData(data: list[list[Union[str, float]]]) -> None:
    """
    Adiciona os dados calculados de média e soma à matriz principal.

    Args:
        data: Lista contendo duas sublistas:
              [0] -> linha de médias
              [1] -> coluna de somas (um valor por supermercado)
    """
    # Adiciona a linha de médias ao final da matriz
    superMarket.append(data[0])

    # Adiciona a soma da cesta básica ao final de cada linha existente
    for row in range(len(superMarket) - 1):
        superMarket[row].append(data[1][row])


def printBeautyData() -> None:
    """
    Exibe a matriz de forma formatada no terminal, com cores para destacar:
    - Verde: menor valor da coluna
    - Vermelho: maior valor da coluna
    """
    GREEN = "\033[92m"
    RED = "\033[91m"
    RESET = "\033[0m"

    rows = superMarket[1:]  # exclui cabeçalho
    cols = len(superMarket[0])

    # Identifica o menor e maior valor de cada coluna (excluindo linha 'Average')
    col_min: list[float] = []
    col_max: list[float] = []
    for col in range(1, cols):  # ignora coluna de nome
        values = [float(row[col]) for row in rows if row[0] != "Average"]
        col_min.append(min(values))
        col_max.append(max(values))

    # Imprime cabeçalho
    for h in superMarket[0]:
        print(f"{h:<12}", end="")
    print()

    # Imprime os dados, aplicando cor onde for necessário
    for row in superMarket[1:]:
        is_average = row[0] == "Average"
        print(f"{row[0]:<12}", end="")
        for col in range(1, len(row)):
            value = float(row[col])
            color = ""
            if not is_average:
                if value == col_min[col - 1]:
                    color = GREEN
                elif value == col_max[col - 1]:
                    color = RED
            print(f"{color}{value:>10.2f}{RESET}", end="")
        print()


# Execução principal
if __name__ == "__main__":
    avgProducts = avgProductsPrice()                   # Calcula média de preços
    basicFoodBasket = basicFoodBasketPerSuperMarket() # Calcula total da cesta básica
    appendData([avgProducts, basicFoodBasket])         # Adiciona os dados calculados
    printBeautyData()                                  # Exibe resultado formatado
