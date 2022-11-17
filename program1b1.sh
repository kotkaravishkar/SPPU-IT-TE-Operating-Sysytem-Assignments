echo "enter the name of address book = "
read fname
touch $fname
echo "adress boook "
echo -e "name\t ID\t address \t MOB_no ">> $fname
ch=0
while [ $ch -lt '8' ]
do
	echo -e "1.create record"
	echo -e "2.view record"
	echo -e "3.insert record"
	echo -e "4.delete record"
	echo -e "5.modify record"
	echo -e "6.serach record"
	echo -e "7.exit"
	echo "enter your choice = "
	read ch
	case $ch in
		 1) echo "enter number of records you want to add = "
			  read n
			   for ((i=0;i<$n;i++))
				    do
					     echo -e "enter the name\t"
					      read ename
					       echo -e "enter the ID\t"
					        read eid
						 echo -e "enter the address "
						  read eadd
						   echo -e "enter the mobile number = "
						   read MOB_no
						    echo -e "$ename \t $eid \t $eadd \t $MOB_no \n " >>$fname
						     done
						      ;;
					      2) echo "view the record"
						      cat $fname
						      ;;
					      3) echo "insert the record"
						       echo "enter number of records you want to add = "
						       read n
						       for ((i=0;i<$n;i++))
						       do
							       echo -e "enter the name\t"
							        read ename
								 echo -e "enter the ID\t"
								 read eid
								 echo -e "enter the address "
								 read eadd
								 echo -e "enter the mobile number = "
								 read MOB_no
								  echo -e "$ename \t $eid \t $eadd \t $MOB_no \n " >>$fname
								   done
								    ;;
							    4) echo "enter employee id to delete the record = "
								    read eid
								     if grep -w $eid $fname
								     then 
									      grep -wv $eid $fname >>temp
									       rm $fname
									        mv temp $fname
										 echo "record deleted "
										  else
											   echo "record does not exist "
											    fi
											     ;;
										     5)
											     echo " enter emp id "
											      read eid
											       if grep -w $eid $fname
												        then
														 grep -wv $eid $fname>>temp
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
											6) echo "enter employee ID to search = "
												 read eid
												  if grep $eid $fname
													   then
														    #grep -w $eid $fname
														     echo "read found "
														      else echo "does not exist"
															       fi
															        ;;
															7) exit
																 ;;
														 esac
													 done
													 echo "enter the name of address book = "
													 read fname
													 touch $fname
													 echo "adress boook "
													 echo -e "name\t ID\t address \t MOB_no ">> $fname
													 ch=0
													 while [True]
													 do
														 echo -e "1.create record"
														 echo -e "2.view record"
														 echo -e "3.insert record"
														 echo -e "4.delete record"
														 echo -e "5.modify record"
														 echo -e "6.serach record"
														 echo -e "7.exit"
														 echo "enter your choice = "
														 read ch
														 case $ch in
															  1) echo "enter number of records you want to add = "
																   read n
																    for ((i=0;i<$n;i++))
																	     do
																		      echo -e "enter the name\t"
																		       read ename
																		        echo -e "enter the ID\t"
																			 read eid
																			  echo -e "enter the address "
																			   read eadd
																			    echo -e "enter the mobile number = "
																			    read MOB_no
																			     echo -e "$ename \t $eid \t $eadd \t $MOB_no \n " >>$fname
																			      done
																			       ;;
																		       2) echo "view the record"
																			       cat $fname
																			       ;;
																		       3) echo "insert the record"
																			        echo "enter number of records you want to add = "
																				read n
																				for ((i=0;i<$n;i++))
																				do
																					echo -e "enter the name\t"
																					 read ename
																					  echo -e "enter the ID\t"
																					  read eid
																					  echo -e "enter the address "
																					  read eadd
																					  echo -e "enter the mobile number = "
																					  read MOB_no
																					   echo -e "$ename \t $eid \t $eadd \t $MOB_no \n " >>$fname
																					    done
																					     ;;
																				     4) echo "enter employee id to delete the record = "
																					     read eid
																					      if grep -w $eid $fname
																					      then 
																						       grep -wv $eid $fname >>temp
																						        rm $fname
																							 mv temp $fname
																							  echo "record deleted "
																							   else
																								    echo "record does not exist "
																								     fi
																								      ;;
																							      5)
																								      echo " enter emp id "
																								       read eid
																								        if grep -w $eid $fname
																										 then
																											  grep -wv $eid $fname>>temp
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
																								 6) echo "enter employee ID to search = "
																									  read eid
																									   if grep $eid $fname
																										    then
																											     #grep -w $eid $fname
																											      echo "read found "
																											       else echo "does not exist"
																												        fi
																													 ;;
																												 7) exit
																													  ;;
																											  esac
																										  done

