echo "Enter The Name Of Address Book : \n"
read fname

touch $fname
echo "Address Book \n "
echo -e "Name\t ID\t address\t Mob_No">>$fname

ch=0
while [ True ]
	do
	echo -e "\t1.Create The Address"
	echo -e "\t2.View Address Book"
	echo -e "\t3.Insert Record"
	echo -e "\t4.Modify Record"
	echo -e "\t5.Search Record"
	echo -e "\t7.Exit"
	echo "Enter Your Choice = "
	read ch

	case $ch in
	1) echo "Enter The No of records you want to add = "
	    read n
	    for ((i=0;i<$n;i++))
	    do
	    echo -e "Enter the name\t"
	    read ename
	    echo -e "ENter The ID\t"
	    read eid
	    echo -e "Enter The Address\t"
	    read eadd
	    echo -e "Enter The Mobile\t"
	    read emob
	     
	    echo -e "$ename\t $eid\t $eadd\t $emob\n">>$fname
	    done
	    ;;

	2) echo "View Address Book \n"
		cat $fname
		;;

	4) echo "Enter The EMPID You want to Modify :\n"
		read eid

		if grep -w $eid $fname 
		then 
			grep -wv $eid $fname >> temp
			rm $fname
			mv temp $fname
			echo -e "modify the record "
		        echo -e "enter the name\t"
		        read ename
		        echo -e "enter the ID\t"
		        read eid
		        echo -e "enter the address "
		        read eadd
		        echo -e "enter the mobile number = "
		        read MOB_no
		        echo -e "$ename \t $eid \t $eadd \t $MOB_no \n " >>$fname
	      else
			   echo "record does not exist "
	      fi
		 ;;
    esac 
done
