import os
import re
from bs4 import BeautifulSoup
from markdownify import markdownify as md

SOURCE_DIR = "/home/gianluke/Scrivania/WokwiWiki"
OUT_DIR = "/media/gianluke/Data/Università/IoT/Li Schiaccianoce /ESP32_Wokwi_Wiki"

EXCLUDE_PARTS = [
    "wokwi-arduino-uno", "wokwi-arduino-mega", "wokwi-arduino-nano",
    "wokwi-pi-pico", "wokwi-franzininho", "board-franzininho-wifi",
    "board-stm32-bluepill", "board-st-nucleo-c031c6", "board-st-nucleo-l031k6",
    "wokwi-attiny85"
]

def clean_html(html_content):
    soup = BeautifulSoup(html_content, 'html.parser')
    
    # Extract main article
    article = soup.find('article')
    if not article:
        return ""
        
    # Remove unwanted sections
    for unwanted in article.find_all(class_=['theme-doc-footer', 'pagination-nav', 'hash-link']):
        unwanted.decompose()
        
    # Remove elements with "Edit this page"
    for edit_link in article.find_all('a', class_='theme-edit-this-page'):
        edit_link.decompose()
        
    # Find headers and remove 'Simulator examples' entirely
    for h2 in article.find_all(['h2', 'h3']):
        if h2.text.strip().lower() in ['simulator examples', 'examples', 'community']:
            # We want to remove the header and the following UL/content until next header
            curr = h2.next_sibling
            while curr and curr.name not in ['h2', 'h3', 'h1']:
                next_sib = curr.next_sibling
                if hasattr(curr, 'decompose'):
                    curr.decompose()
                curr = next_sib
            h2.decompose()

    # Pre-process pre > code blocks to add language if possible
    # We can do this with regex post-markdownify
    return str(article)

def convert_to_markdown(html_str, filename):
    # Convert using markdownify
    markdown = md(html_str, heading_style="ATX", default_title=True, escape_asterisks=False)
    
    # Fix code blocks (heuristic: if it looks like json, mark it json)
    def code_replacer(match):
        code_content = match.group(1)
        if "{" in code_content and "}" in code_content and ":" in code_content:
            return f"```json\n{code_content.strip()}\n```"
        elif "setup()" in code_content or "loop()" in code_content or "#include" in code_content:
            return f"```cpp\n{code_content.strip()}\n```"
        else:
            return f"```text\n{code_content.strip()}\n```"
            
    markdown = re.sub(r'```(.*?)```', code_replacer, markdown, flags=re.DOTALL)
    
    # Fix links (e.g. wokwi-led.html to wokwi-led.md)
    markdown = re.sub(r'href="([^"]+)\.html(#?[^"]*)"', r'href="\1.md\2"', markdown)
    # Markdown links: [Text](link.html) to [Text](link.md)
    markdown = re.sub(r'\]\(([^)]+)\.html(#?[^)]*)\)', r'](\1.md\2)', markdown)
    # Markdown links: [Text](../parts/link.html) to [Text](link.md)
    markdown = re.sub(r'\]\(\.\./parts/([^)]+)\.html(#?[^)]*)\)', r'](\1.md\2)', markdown)
    markdown = re.sub(r'\]\(\.\./([^)]+)\.html(#?[^)]*)\)', r'](\1.md\2)', markdown)
    
    # Clean up excessive newlines
    markdown = re.sub(r'\n{3,}', '\n\n', markdown)
    
    return markdown.strip()

def process_file(source_path, out_filename):
    if not os.path.exists(source_path):
        print(f"File not found: {source_path}")
        return
        
    with open(source_path, 'r', encoding='utf-8') as f:
        html = f.read()
        
    clean = clean_html(html)
    markdown = convert_to_markdown(clean, out_filename)
    
    if markdown:
        with open(os.path.join(OUT_DIR, out_filename), 'w', encoding='utf-8') as f:
            f.write(markdown)
        print(f"Generated {out_filename}")
        return True
    return False

def main():
    os.makedirs(OUT_DIR, exist_ok=True)
    
    index_links = []
    
    # Core Guides
    print("Processing guides...")
    if process_file(os.path.join(SOURCE_DIR, 'guides/esp32.html'), 'esp32-boards.md'):
        index_links.append(("- Schede ESP32 (Specifiche e Limitazioni)", "esp32-boards.md"))
    if process_file(os.path.join(SOURCE_DIR, 'guides/esp32-wifi.html'), 'esp32-wifi.md'):
        index_links.append(("- Simulazione WiFi ESP32", "esp32-wifi.md"))
    if process_file(os.path.join(SOURCE_DIR, 'diagram-format.html'), 'diagram-json.md'):
        index_links.append(("- Configurazione diagram.json", "diagram-json.md"))
        
    # Parts
    print("Processing parts...")
    parts_dir = os.path.join(SOURCE_DIR, 'parts')
    part_links = []
    if os.path.exists(parts_dir):
        for f in os.listdir(parts_dir):
            if f.endswith('.html'):
                base_name = f.replace('.html', '')
                if base_name in EXCLUDE_PARTS:
                    continue
                out_name = f"{base_name}.md"
                if process_file(os.path.join(parts_dir, f), out_name):
                    part_links.append((f"- {base_name.replace('wokwi-', '').replace('-', ' ').title()}", out_name))
    
    part_links.sort()
    
    # Generate Index
    index_content = "# Wokwi ESP32 - Documentazione Tecnica\n\n"
    index_content += "Questa Wiki raccoglie la documentazione essenziale per l'utilizzo dell'ambiente di simulazione Wokwi con focus esclusivo sull'ecosistema **ESP32**.\n\n"
    index_content += "## 📖 Guide Fondamentali\n"
    for title, link in index_links:
        index_content += f"{title}: [{link}]({link})\n"
        
    index_content += "\n## 🧩 Componenti Elettronici Supportati\n"
    for title, link in part_links:
        index_content += f"{title}: [{link}]({link})\n"
        
    with open(os.path.join(OUT_DIR, 'index.md'), 'w', encoding='utf-8') as f:
        f.write(index_content)
    print("Generated index.md")

if __name__ == '__main__':
    main()
