def rotate_layer(sub, layer, n):
    cur = []
    pos = []
    
   
    
    for c in range(layer - 1, n - layer + 1):
        pos.append((layer - 1, c))
        cur.append(sub[layer - 1][c])

    
    for r in range(layer, n - layer):
        pos.append((r, n - layer))
        cur.append(sub[r][n - layer])

    
    for c in range(n - layer, layer - 2, -1):
        pos.append((n - layer, c))
        cur.append(sub[n - layer][c])

   
    for r in range(n - layer - 1, layer - 1, -1):
        pos.append((r, layer - 1))
        cur.append(sub[r][layer - 1])

    
    if layer % 2 == 1:
        rotate = layer % len(cur)
        rotated = cur[rotate:] + cur[:rotate]
        rotated = [chr(((ord(c) - ord('A') - 1) % 26) + ord('A')) for c in rotated]
    else:
        
        rotate = layer % len(cur)
        rotated = cur[-rotate:] + cur[:-rotate]
        rotated = [chr(((ord(c) - ord('A') + 1) % 26) + ord('A')) for c in rotated]

   
    for pos, val in zip(pos, rotated):
        r, c = pos
        sub[r][c] = val

def rotate_submatrix(mat, row, col, n):
    sub = [row_list[col:col+n] for row_list in mat[row:row+n]]

    layers = n // 2
    for layer in range(1, layers + 1):
        rotate_layer(sub, layer, n)


    for r in range(n):
        for c in range(n):
            mat[row + r][col + c] = sub[r][c]

def query(mat, queries):
    for query in queries:
        row, col, n = query
        rotate_submatrix(mat, row, col, n)

def print_result(mat):
    res = ''.join([''.join(row) for row in mat])
    print(res)


N = int(input().strip()) 
mat = [input().strip().split() for _ in range(N)] 

K = int(input().strip())  
queries = [tuple(map(int, input().split())) for _ in range(K)]
 
query(mat, queries)
print_result(mat)