from pathlib import Path
import re

def extract_targets(makefile_path):
    pattern = re.compile(r'otool\s+-tvV\s+(\./\S+)\s*>\s*(\S+)')
    results = []
    
    with open(makefile_path, 'r') as f:
        for line in f:
            match = pattern.search(line)
            if match:
                input_binary = match.group(1)
                output_file = match.group(2)
                results.append((input_binary, output_file))
    
    return results


if __name__ == "__main__":
    makefile = "Makefile"
    pairs = extract_targets(makefile)
    
    for inp, out in pairs:
        Path(inp).unlink(missing_ok=True)
        Path(out).unlink(missing_ok=True)