import requests

headers = {
    'Content-Type': 'application/json',
    'Accept': 'application/json',
    'Grpc-Metadata-Authorization': 'Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJhdWQiOiJjaGlycHN0YWNrLWFwcGxpY2F0aW9uLXNlcnZlciIsImV4cCI6MTU3OTYxMzc0MywiaXNzIjoiY2hpcnBzdGFjay1hcHBsaWNhdGlvbi1zZXJ2ZXIiLCJuYmYiOjE1Nzk1MjczNDMsInN1YiI6InVzZXIiLCJ1c2VybmFtZSI6ImFkbWluIn0.AnOKRHrzPIjrLCyoLA61eX0tIJf7HENNmxHYYiDdOPU',
}
f=open('info.txt', 'a')
response = requests.get('http://localhost:8080/api/devices/46486480ee125f27/events', headers=headers)
#response = requests.get('http://localhost:8080/api/devices/46486480ee125f27/frames?limit=10', headers=headers)
print(response.text)
print('as')
f.write(response.text)