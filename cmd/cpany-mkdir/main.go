package main

import (
	"errors"
	"io/ioutil"
	"log"
	"os"
	"path"
	"path/filepath"
)

func toAbs(file string) (string, error) {
	if filepath.IsAbs(file) {
		return file, nil
	}
	dir, err := os.Getwd()
	if err != nil {
		return "", err
	}
	abs, err := filepath.Abs(filepath.Join(dir, file))
	if err != nil {
		return "", err
	}
	return abs, nil
}

func exists(path string) (bool, error) {
	_, err := os.Stat(path)
	if err == nil {
		return true, nil
	}
	if os.IsNotExist(err) {
		return false, nil
	}
	return false, err
}

func run() error {
	if len(os.Args) == 1 {
		return errors.New("usage: cpany mkdir [dir]")
	}
	dir, err := toAbs(os.Args[1])
	if err != nil {
		return err
	}
	if err := os.MkdirAll(dir, 0755); err != nil {
		return err
	}
	mainCC := path.Join(dir, "main.cc")
	if e, err := exists(mainCC); err != nil {
		return err
	} else if !e {
		const tmpl = `#include <bits/stdc++.h>

#include "cpany.h"

void Main() {
}`
		if err := ioutil.WriteFile(mainCC, []byte(tmpl), 0644); err != nil {
			return err
		}
	}
	if err := os.MkdirAll(filepath.Join(dir, "test"), 0755); err != nil {
		return err
	}
	return nil
}

func main() {
	if err := run(); err != nil {
		log.Println(err)
		os.Exit(1)
	}
}
