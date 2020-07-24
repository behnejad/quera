import bs4


def process(name):
    with open(name) as f:
        soup = bs4.BeautifulSoup(f)
    return len([link['href'] for link in soup('a') if 'href' in link.attrs])
