import requests

headers = {
    'Content-Type': 'application/json',
    'Accept': 'application/json',
    'Grpc-Metadata-Authorization': 'Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJhdWQiOiJjaGlycHN0YWNrLWFwcGxpY2F0aW9uLXNlcnZlciIsImV4cCI6MTU3OTYxMzc0MywiaXNzIjoiY2hpcnBzdGFjay1hcHBsaWNhdGlvbi1zZXJ2ZXIiLCJuYmYiOjE1Nzk1MjczNDMsInN1YiI6InVzZXIiLCJ1c2VybmFtZSI6ImFkbWluIn0.AnOKRHrzPIjrLCyoLA61eX0tIJf7HENNmxHYYiDdOPU',
}

data = '{"password": "admin","username": "admin"}'

response = requests.post('http://localhost:8080/api/internal/login', headers=headers, data=data)

print(response.text)