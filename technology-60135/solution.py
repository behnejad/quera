from bs4 import BeautifulSoup


def process(file_name):
    with open(file_name, 'r') as file:
        data = file.read().replace('\n', '')

    soup = BeautifulSoup(data, "html.parser")

    count = 0

    for link in soup.find_all('a'):
        # print(link.get('href'))
        count += 1

    return count
