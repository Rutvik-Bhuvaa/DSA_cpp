1. Row Major

=> index = ((rowIndex) x cols) + colIndex
=> If index is given then
rowIndex = index/cols,
colIndex = index%cols

2. Column Major --> prefered most for practical use case

=> index=((colIndex) x rows) + rowIndex
=> If index is given then
rowIndex = index%rows,
colIndex = index/rows
