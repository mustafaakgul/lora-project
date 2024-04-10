import requests
import time
from requests.adapters import HTTPAdapter
from requests.packages.urllib3.util.retry import Retry

headers = {
    'Accept': 'application/json',
    'Content-Type': 'application/json',
    'Grpc-Metadata-Authorization': 'Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJhdWQiOiJjaGlycHN0YWNrLWFwcGxpY2F0aW9uLXNlcnZlciIsImV4cCI6MTU3OTYxMzc0MywiaXNzIjoiY2hpcnBzdGFjay1hcHBsaWNhdGlvbi1zZXJ2ZXIiLCJuYmYiOjE1Nzk1MjczNDMsInN1YiI6InVzZXIiLCJ1c2VybmFtZSI6ImFkbWluIn0.AnOKRHrzPIjrLCyoLA61eX0tIJf7HENNmxHYYiDdOPU',
}

while(1):
    response = requests.get('http://localhost:8080/api/devices/46486480ee125f27/frames', headers=headers)
    print(response.text)
    time.sleep(0.2)