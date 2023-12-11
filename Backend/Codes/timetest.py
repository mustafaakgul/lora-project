
from datetime import datetime
from apscheduler.schedulers.blocking import BlockingScheduler

def job_function():
    print('hello')

sched = BlockingScheduler()

sched.add_job(job_function, 'interval', seconds=5)

sched.start()