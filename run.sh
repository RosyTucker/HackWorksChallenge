#!/usr/bin/env bash

if [ -z $1 ];
then
  echo "You must specify your device name"
  exit 1
fi;

rm photon_firmware_*
output=$(particle compile photon . | tail -1 | grep -o photon_firmware_.*\.bin)
echo "Create firmware: $output"
particle flash $1 $output
