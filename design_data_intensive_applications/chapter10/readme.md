batch processing by unix tool 

cat ngix_access_log| awk '{print $7}' | sort | uniq -c | sort -r  -n  | he
ad -n 5
