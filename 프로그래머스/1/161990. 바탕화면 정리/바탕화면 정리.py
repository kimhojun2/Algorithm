def solution(wallpaper):
    answer = []
    R = len(wallpaper)
    C = len(wallpaper[0])
    M_x = -1
    m_x = C
    M_y = -1
    m_y = R
    for i in range(R):
        for j in range(C):
            if wallpaper[i][j] == '#':
                if i > M_y:
                    M_y = i
                if j > M_x:
                    M_x = j
                if i < m_y:
                    m_y = i
                if j < m_x:
                    m_x = j
    
            
    return [m_y, m_x, M_y+1, M_x+1]