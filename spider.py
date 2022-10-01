#!/usr/bin/env python3

import requests
import re
import argparse
from urllib.parse import urljoin

def get_argument():
    parser = argparse.ArgumentParser()
    parser.add_argument("-t", "--target", dest="target", help="Target URL.")
    options = parser.parse_args()
    if not options.target:
        parser.error("[-] Please specify target domain, use -h or --help for more info.")
    return options

def extract_links(response):
    href_links = re.findall('(?:href=")(.*?)"', response)
    return href_links

def request(url):
    try:
        return requests.get(url)
    except requests.exceptions.ConnectionError:
        pass

def spider_crawl(url):
    response = request(options.target)
    href_links = extract_links(str(response.content))
    for link in href_links:
        link = urljoin(url, link)
        
        if '#' in link:
            link = link.split('#')[0]
    
        if url in link and link not in visited:
            visited.append(link)
            print("\n"+link)
            spider_crawl(link)

options = get_argument()
visited = []
try:
    spider_crawl(options.target)
except KeyboardInterrupt:
	print("\n[+] Stopping the Spider")