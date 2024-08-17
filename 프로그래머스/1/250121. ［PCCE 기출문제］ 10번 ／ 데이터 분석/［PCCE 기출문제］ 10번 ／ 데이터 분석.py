def solution(data, ext, val_ext, sort_by):
    answer = []
    n = -1
    exts = ['code', 'date', 'maximum', 'remain']
    n = exts.index(ext)
    m = exts.index(sort_by)
    for d in data:
        if d[n] < val_ext:
            answer.append(d)
    
    new = sorted(answer, key=lambda x:x[m])
        
    return new