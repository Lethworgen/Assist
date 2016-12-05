## assits scraper must be running on localhost port 8081
## run npm start in Assistscraper dir

import requests as r
import json

UCs = r.get ("http://localhost:8081/api/DAC/oias")
UCs = UCs.json()
for n in range(len(UCs)):
    UCs[n]["id"] = n
    
with open("dac_ucs.json", "w") as fp:
    json.dump(UCs, fp)
    
majors = []
for UC in UCs:
    http_str = "http://localhost:8081/api/DAC/"+str(UC['value'])+"/dora"
    uc_majors = r.get(http_str).json()
    if uc_majors == "Error with school name":
        print str(UC['value']) + " N/A"
        continue
    
    for n in range(len(uc_majors)):
        uc_majors[n]['id'] = n
        uc_majors[n]["uc_val"] = UC["value"]
        uc_majors[n]['ucId'] = UC['id']
    majors += uc_majors
    
with open("DAC_UC_majors.json", 'w') as fp:
    json.dump(majors, fp)
    
courses = []
for m in majors:
    "http://localhost:8081/api/DAC/"+str(m['uc_val'])+"/"+str(m['value'])+"/courses"
    major_courses = r.get(http_str).json()
    for n in range(len(major_courses)):
        major_courses[n]['id'] = n
        major_courses[n]["major_id"] = m['id']
    courses += major_courses

with open("uc_dac_courses.json", "w") as fp:
    json.dump(courses, fp)