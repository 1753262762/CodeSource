import time
import sys
import os
import pygame.mixer

class Credits_BGA:

    bpm = 179
    beat_time = 60 / bpm
    half_beat_time = 60 / bpm / 2
    quarter_beat_time = 60 / bpm / 4
    half_quarter_beat_time = 60 / bpm / 8

    light = '\xb0'
    median = '\xb1'
    dark = '\xb2'
    smile = '\xb3'
    eighth_note = '\xb4'
    sixteenth_note = '\xb5'

    def __init__(self):
        os.system('cls')
        pygame.mixer.init()
        pygame.mixer.music.load('credits.mp3')
        time.sleep(2)
        print('\x1b[?25l')
        pygame.mixer.music.play(start = 0)
        self._1()
        self._2()
        self._3()
        self._4()
        self._5()
        self._6()
        self._7()
        self._8()

    
    def output(self, text:str, wait_time:float):
        sys.stdout.write('\033[2J')
        sys.stdout.write('\033[H')
        sys.stdout.write(text)
        time.sleep(wait_time)

    def _1(self):

        frames = {"beginning1":'THE BMS FIGHTER ULTIMATE\n\n               Smith au Lait', 
                  "beginning2":'THE BMS FIGHTER ULTIMATE\n\n               Smith au Lait\n\nMusic: Frums\n\n                  BGA: Frums',
                  "beginning3":'THE BMS FIGHTER ULTIMATE\n\n               Smith au Lait\n\nMusic: Frums\n\n                  BGA: Frums\n\nGenre: OTHER TIME\n\n                    BPM: 179',
                  "beginning4":'THE BMS FIGHTER ULTIMATE\n\n               Smith au Lait\n\nMusic: Frums\n\n                  BGA: Frums\n\nGenre: OTHER TIME\n\n                    BPM: 179\n\nCredits',
                  "01":' 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n'*7,
                  "02":'0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n'*7
        }

        def _():
            for i in range(4):
                self.output(frames['01'], self.quarter_beat_time)
                self.output(frames['02'], self.quarter_beat_time)

        self.output(frames['beginning1'], 6*self.beat_time)
        _()
        self.output(frames['beginning2'], 6*self.beat_time)
        _()
        self.output(frames['beginning3'], 6*self.beat_time)
        _()
        self.output(frames['beginning4'], 6*self.beat_time)
        _()

    def _2(self):
        def ender_pearl(char:str, type:bool, wait_time:float):
            if type ==0:
                self.output(f'Credits\n\n            {2*self.eighth_note}{2*self.sixteenth_note}\n        {6*self.eighth_note}{6*self.sixteenth_note}\n      {8*self.eighth_note}{8*self.sixteenth_note}\n      {6*self.eighth_note}{4*char}{6*self.sixteenth_note}\n    {6*self.eighth_note}{8*char}{6*self.sixteenth_note}\n    {6*self.sixteenth_note}{8*char}{6*self.eighth_note}\n      {6*self.sixteenth_note}{4*char}{6*self.eighth_note}\n      {8*self.sixteenth_note}{8*self.eighth_note}\n        {6*self.sixteenth_note}{6*self.eighth_note}\n            {2*self.sixteenth_note}{2*self.eighth_note}\n\n                       Frums', wait_time)
            elif type ==1:
                self.output(f'Credits\n\n            {2*self.sixteenth_note}{2*self.eighth_note}\n        {6*self.sixteenth_note}{6*self.eighth_note}\n      {8*self.sixteenth_note}{8*self.eighth_note}\n      {6*self.sixteenth_note}{4*char}{6*self.eighth_note}\n    {6*self.sixteenth_note}{8*char}{6*self.eighth_note}\n    {6*self.eighth_note}{8*char}{6*self.sixteenth_note}\n      {6*self.eighth_note}{4*char}{6*self.sixteenth_note}\n      {8*self.eighth_note}{8*self.sixteenth_note}\n        {6*self.eighth_note}{6*self.sixteenth_note}\n            {2*self.eighth_note}{2*self.sixteenth_note}\n\n                       Frums', wait_time)
        for j in range(4):
            for i in range(2):
                ender_pearl('\xea', 0, self.half_beat_time)
                ender_pearl('.', 0, self.half_beat_time)
                ender_pearl('\xf7', 0, self.half_beat_time)
            for i in range(2):
                ender_pearl('\xea', 0, self.half_beat_time)
                ender_pearl('.', 0, self.half_beat_time)
            ender_pearl('\xf7', 0, self.half_beat_time)
            ender_pearl('\xea', 1, self.half_beat_time)
            for k in range(8):
                ender_pearl('\xf1', 1, self.half_quarter_beat_time)
                ender_pearl('.', 1, self.half_quarter_beat_time)
    
    def _3(self):
        def ender_pearl(char:str, type:bool, wait_time:float, shine:int, text:bool):
            if type ==0:
                if shine ==0:
                    self.output(f'Credits\n\n  {2*self.light}        {2*self.eighth_note}{2*self.sixteenth_note}        {2*self.light}\n {2*self.light}     {6*self.eighth_note}{6*self.sixteenth_note}     {2*self.light}\n {2*self.light}   {8*self.eighth_note}{8*self.sixteenth_note}   {2*self.light}\n{2*self.light}    {6*self.eighth_note}{4*char}{6*self.sixteenth_note}    {2*self.light}\n{2*self.light}  {6*self.eighth_note}{8*char}{6*self.sixteenth_note}  {2*self.light}\n{2*self.light}  {6*self.sixteenth_note}{8*char}{6*self.eighth_note}  {2*self.light}\n{2*self.light}    {6*self.sixteenth_note}{4*char}{6*self.eighth_note}    {2*self.light}\n {2*self.light}   {8*self.sixteenth_note}{8*self.eighth_note}   {2*self.light}\n {2*self.light}     {6*self.sixteenth_note}{6*self.eighth_note}     {2*self.light}\n  {2*self.light}        {2*self.sixteenth_note}{2*self.eighth_note}        {2*self.light}\n\n{self.smile+' F' if text==1 else '   '}                    Frums', wait_time)
                elif shine ==1:
                    self.output(f'Credits\n\n  {2*self.median}        {2*self.eighth_note}{2*self.sixteenth_note}        {2*self.median}\n {2*self.median}     {6*self.eighth_note}{6*self.sixteenth_note}     {2*self.median}\n {2*self.median}   {8*self.eighth_note}{8*self.sixteenth_note}   {2*self.median}\n{2*self.median}    {6*self.eighth_note}{4*char}{6*self.sixteenth_note}    {2*self.median}\n{2*self.median}  {6*self.eighth_note}{8*char}{6*self.sixteenth_note}  {2*self.median}\n{2*self.median}  {6*self.sixteenth_note}{8*char}{6*self.eighth_note}  {2*self.median}\n{2*self.median}    {6*self.sixteenth_note}{4*char}{6*self.eighth_note}    {2*self.median}\n {2*self.median}   {8*self.sixteenth_note}{8*self.eighth_note}   {2*self.median}\n {2*self.median}     {6*self.sixteenth_note}{6*self.eighth_note}     {2*self.median}\n  {2*self.median}        {2*self.sixteenth_note}{2*self.eighth_note}        {2*self.median}\n\n{self.smile+' F' if text==1 else '   '}                    Frums', wait_time)
                elif shine ==2:
                    self.output(f'Credits\n\n  {2*self.dark}        {2*self.eighth_note}{2*self.sixteenth_note}        {2*self.dark}\n {2*self.dark}     {6*self.eighth_note}{6*self.sixteenth_note}     {2*self.dark}\n {2*self.dark}   {8*self.eighth_note}{8*self.sixteenth_note}   {2*self.dark}\n{2*self.dark}    {6*self.eighth_note}{4*char}{6*self.sixteenth_note}    {2*self.dark}\n{2*self.dark}  {6*self.eighth_note}{8*char}{6*self.sixteenth_note}  {2*self.dark}\n{2*self.dark}  {6*self.sixteenth_note}{8*char}{6*self.eighth_note}  {2*self.dark}\n{2*self.dark}    {6*self.sixteenth_note}{4*char}{6*self.eighth_note}    {2*self.dark}\n {2*self.dark}   {8*self.sixteenth_note}{8*self.eighth_note}   {2*self.dark}\n {2*self.dark}     {6*self.sixteenth_note}{6*self.eighth_note}     {2*self.dark}\n  {2*self.dark}        {2*self.sixteenth_note}{2*self.eighth_note}        {2*self.dark}\n\n{self.smile+' F' if text==1 else '   '}                    Frums', wait_time)
            elif type ==1:
                if shine ==0:
                    self.output(f'Credits\n\n  {2*self.light}        {2*self.sixteenth_note}{2*self.eighth_note}        {2*self.light}\n {2*self.light}     {6*self.sixteenth_note}{6*self.eighth_note}     {2*self.light}\n {2*self.light}   {8*self.sixteenth_note}{8*self.eighth_note}   {2*self.light}\n{2*self.light}    {6*self.sixteenth_note}{4*char}{6*self.eighth_note}    {2*self.light}\n{2*self.light}  {6*self.sixteenth_note}{8*char}{6*self.eighth_note}  {2*self.light}\n{2*self.light}  {6*self.eighth_note}{8*char}{6*self.sixteenth_note}  {2*self.light}\n{2*self.light}    {6*self.eighth_note}{4*char}{6*self.sixteenth_note}    {2*self.light}\n {2*self.light}   {8*self.eighth_note}{8*self.sixteenth_note}   {2*self.light}\n {2*self.light}     {6*self.eighth_note}{6*self.sixteenth_note}     {2*self.light}\n  {2*self.light}        {2*self.eighth_note}{2*self.sixteenth_note}        {2*self.light}\n\n{self.smile+' F' if text==1 else '   '}                    Frums', wait_time)
                elif shine ==1:
                    self.output(f'Credits\n\n  {2*self.median}        {2*self.sixteenth_note}{2*self.eighth_note}        {2*self.median}\n {2*self.median}     {6*self.sixteenth_note}{6*self.eighth_note}     {2*self.median}\n {2*self.median}   {8*self.sixteenth_note}{8*self.eighth_note}   {2*self.median}\n{2*self.median}    {6*self.sixteenth_note}{4*char}{6*self.eighth_note}    {2*self.median}\n{2*self.median}  {6*self.sixteenth_note}{8*char}{6*self.eighth_note}  {2*self.median}\n{2*self.median}  {6*self.eighth_note}{8*char}{6*self.sixteenth_note}  {2*self.median}\n{2*self.median}    {6*self.eighth_note}{4*char}{6*self.sixteenth_note}    {2*self.median}\n {2*self.median}   {8*self.eighth_note}{8*self.sixteenth_note}   {2*self.median}\n {2*self.median}     {6*self.eighth_note}{6*self.sixteenth_note}     {2*self.median}\n  {2*self.median}        {2*self.eighth_note}{2*self.sixteenth_note}        {2*self.median}\n\n{self.smile+' F' if text==1 else '   '}                    Frums', wait_time)
                elif shine ==2:
                    self.output(f'Credits\n\n  {2*self.dark}        {2*self.sixteenth_note}{2*self.eighth_note}        {2*self.dark}\n {2*self.dark}     {6*self.sixteenth_note}{6*self.eighth_note}     {2*self.dark}\n {2*self.dark}   {8*self.sixteenth_note}{8*self.eighth_note}   {2*self.dark}\n{2*self.dark}    {6*self.sixteenth_note}{4*char}{6*self.eighth_note}    {2*self.dark}\n{2*self.dark}  {6*self.sixteenth_note}{8*char}{6*self.eighth_note}  {2*self.dark}\n{2*self.dark}  {6*self.eighth_note}{8*char}{6*self.sixteenth_note}  {2*self.dark}\n{2*self.dark}    {6*self.eighth_note}{4*char}{6*self.sixteenth_note}    {2*self.dark}\n {2*self.dark}   {8*self.eighth_note}{8*self.sixteenth_note}   {2*self.dark}\n {2*self.dark}     {6*self.eighth_note}{6*self.sixteenth_note}     {2*self.dark}\n  {2*self.dark}        {2*self.eighth_note}{2*self.sixteenth_note}        {2*self.dark}\n\n{self.smile+' F' if text==1 else '   '}                    Frums', wait_time)
        for i in range(4):
            ender_pearl('\xea', 0, self.half_quarter_beat_time/2, 2,0)
            ender_pearl('\xea', 0, self.half_quarter_beat_time/2, 1,0)
            ender_pearl('\xea', 0, self.half_quarter_beat_time, 0, 0)
            ender_pearl('.', 0, self.half_beat_time, 0, 0)
            ender_pearl('\xf7', 0, self.half_beat_time, 0, 0)
            ender_pearl('\xea', 0, self.half_beat_time, 0, 0)
            ender_pearl('.', 0, self.half_quarter_beat_time/2, 2, 0)
            ender_pearl('.', 0, self.half_quarter_beat_time/2, 1, 0)
            ender_pearl('.', 0, self.half_quarter_beat_time, 0, 0)
            ender_pearl('\xf7', 0, self.half_beat_time, 0, 0)
            ender_pearl('\xea', 0, self.half_beat_time, 0, 0)
            ender_pearl('.', 0, self.half_beat_time, 0, 0)
            ender_pearl('\xea', 0, self.half_quarter_beat_time/2, 2, 0)
            ender_pearl('\xea', 0, self.half_quarter_beat_time/2, 1, 0)
            ender_pearl('\xea', 0, self.half_quarter_beat_time, 0, 0)
            ender_pearl('.', 0, self.half_beat_time, 0, 0)
            ender_pearl('\xf7', 0, self.half_beat_time, 0, 0)
            ender_pearl('\xea', 0, self.half_quarter_beat_time/2, 2, 0)
            ender_pearl('\xea', 0, self.half_quarter_beat_time/2, 1, 0)
            ender_pearl('\xea', 0, self.half_quarter_beat_time, 0, 0)
            ender_pearl('\xea', 0, self.half_beat_time, 0, 0)
            ender_pearl('.', 0, self.half_quarter_beat_time/2, 2, 0)
            ender_pearl('.', 0, self.half_quarter_beat_time/2, 1, 0)
            ender_pearl('.', 0, self.half_quarter_beat_time, 0, 0)
            for j in range(8):
                ender_pearl('\xf1', 1, self.half_quarter_beat_time, 0, 1 if i==3 else 0)
                ender_pearl('.', 1, self.half_quarter_beat_time, 0, 0)
    
    def _4(self):
        def ender_pearl(char:str, type:bool, wait_time:float, shine:int, text:str):
            if type ==0:
                if shine ==0:
                    self.output(f'Credits\n\n  {2*self.light}        {2*self.eighth_note}{2*self.sixteenth_note}        {2*self.light}\n {2*self.light}     {6*self.eighth_note}{6*self.sixteenth_note}     {2*self.light}\n {2*self.light}   {8*self.eighth_note}{8*self.sixteenth_note}   {2*self.light}\n{2*self.light}    {6*self.eighth_note}{4*char}{6*self.sixteenth_note}    {2*self.light}\n{2*self.light}  {6*self.eighth_note}{8*char}{6*self.sixteenth_note}  {2*self.light}\n{2*self.light}  {6*self.sixteenth_note}{8*char}{6*self.eighth_note}  {2*self.light}\n{2*self.light}    {6*self.sixteenth_note}{4*char}{6*self.eighth_note}    {2*self.light}\n {2*self.light}   {8*self.sixteenth_note}{8*self.eighth_note}   {2*self.light}\n {2*self.light}     {6*self.sixteenth_note}{6*self.eighth_note}     {2*self.light}\n  {2*self.light}        {2*self.sixteenth_note}{2*self.eighth_note}        {2*self.light}\n\n{self.smile +' ' + text}Frums', wait_time)
                elif shine ==1:
                    self.output(f'Credits\n\n  {2*self.median}        {2*self.eighth_note}{ 2*self.sixteenth_note}        {2*self.median}\n {2*self.median}     {6*self.eighth_note}{6*self.sixteenth_note}     {2*self.median}\n {2*self.median}   {8*self.eighth_note}{8*self.sixteenth_note}   {2*self.median}\n{2*self.median}    {6*self.eighth_note}{4*char}{6*self.sixteenth_note}    {2*self.median}\n{2*self.median}  {6*self.eighth_note}{8*char}{6*self.sixteenth_note}  {2*self.median}\n{2*self.median}  {6*self.sixteenth_note}{8*char}{6*self.eighth_note}  {2*self.median}\n{2*self.median}    {6*self.sixteenth_note}{4*char}{6*self.eighth_note}    {2*self.median}\n {2*self.median}   {8*self.sixteenth_note}{8*self.eighth_note}   {2*self.median}\n {2*self.median}     {6*self.sixteenth_note}{6*self.eighth_note}     {2*self.median}\n  {2*self.median}        {2*self.sixteenth_note}{2*self.eighth_note}        {2*self.median}\n\n{self.smile +' ' + text}Frums', wait_time)
                elif shine ==2:
                    self.output(f'Credits\n\n  {2*self.dark}        {2*self.eighth_note}{2*self.sixteenth_note}        {2*self.dark}\n {2*self.dark}     {6*self.eighth_note}{6*self.sixteenth_note}     {2*self.dark}\n {2*self.dark}   {8*self.eighth_note}{8*self.sixteenth_note}   {2*self.dark}\n{2*self.dark}    {6*self.eighth_note}{4*char}{6*self.sixteenth_note}    {2*self.dark}\n{2*self.dark}  {6*self.eighth_note}{8*char}{6*self.sixteenth_note}  {2*self.dark}\n{2*self.dark}  {6*self.sixteenth_note}{8*char}{6*self.eighth_note}  {2*self.dark}\n{2*self.dark}    {6*self.sixteenth_note}{4*char}{6*self.eighth_note}    {2*self.dark}\n {2*self.dark}   {8*self.sixteenth_note}{8*self.eighth_note}   {2*self.dark}\n {2*self.dark}     {6*self.sixteenth_note}{6*self.eighth_note}     {2*self.dark}\n  {2*self.dark}        {2*self.sixteenth_note}{2*self.eighth_note}        {2*self.dark}\n\n{self.smile +' ' + text}Frums', wait_time)
            elif type ==1:
                if shine ==0:
                    self.output(f'Credits\n\n  {2*self.light}        {2*self.sixteenth_note}{2*self.eighth_note}        {2*self.light}\n {2*self.light}     {6*self.sixteenth_note}{6*self.eighth_note}     {2*self.light}\n {2*self.light}   {8*self.sixteenth_note}{8*self.eighth_note}   {2*self.light}\n{2*self.light}    {6*self.sixteenth_note}{4*char}{6*self.eighth_note}    {2*self.light}\n{2*self.light}  {6*self.sixteenth_note}{8*char}{6*self.eighth_note}  {2*self.light}\n{2*self.light}  {6*self.eighth_note}{8*char}{6*self.sixteenth_note}  {2*self.light}\n{2*self.light}    {6*self.eighth_note}{4*char}{6*self.sixteenth_note}    {2*self.light}\n {2*self.light}   {8*self.eighth_note}{8*self.sixteenth_note}   {2*self.light}\n {2*self.light}     {6*self.eighth_note}{6*self.sixteenth_note}     {2*self.light}\n  {2*self.light}        {2*self.eighth_note}{2*self.sixteenth_note}        {2*self.light}\n\n{self.smile +' ' + text}Frums', wait_time)
                elif shine ==1:
                    self.output(f'Credits\n\n  {2*self.median}        {2*self.sixteenth_note}{2*self.eighth_note}        {2*self.median}\n {2*self.median}     {6*self.sixteenth_note}{6*self.eighth_note}     {2*self.median}\n {2*self.median}   {8*self.sixteenth_note}{8*self.eighth_note}   {2*self.median}\n{2*self.median}    {6*self.sixteenth_note}{4*char}{6*self.eighth_note}    {2*self.median}\n{2*self.median}  {6*self.sixteenth_note}{8*char}{6*self.eighth_note}  {2*self.median}\n{2*self.median}  {6*self.eighth_note}{8*char}{6*self.sixteenth_note}  {2*self.median}\n{2*self.median}    {6*self.eighth_note}{4*char}{6*self.sixteenth_note}    {2*self.median}\n {2*self.median}   {8*self.eighth_note}{8*self.sixteenth_note}   {2*self.median}\n {2*self.median}     {6*self.eighth_note}{6*self.sixteenth_note}     {2*self.median}\n  {2*self.median}        {2*self.eighth_note}{2*self.sixteenth_note}        {2*self.median}\n\n{self.smile +' ' + text}Frums', wait_time)
                elif shine ==2:
                    self.output(f'Credits\n\n  {2*self.dark}        {2*self.sixteenth_note}{2*self.eighth_note}        {2*self.dark}\n {2*self.dark}     {6*self.sixteenth_note}{6*self.eighth_note}     {2*self.dark}\n {2*self.dark}   {8*self.sixteenth_note}{8*self.eighth_note}   {2*self.dark}\n{2*self.dark}    {6*self.sixteenth_note}{4*char}{6*self.eighth_note}    {2*self.dark}\n{2*self.dark}  {6*self.sixteenth_note}{8*char}{6*self.eighth_note}  {2*self.dark}\n{2*self.dark}  {6*self.eighth_note}{8*char}{6*self.sixteenth_note}  {2*self.dark}\n{2*self.dark}    {6*self.eighth_note}{4*char}{6*self.sixteenth_note}    {2*self.dark}\n {2*self.dark}   {8*self.eighth_note}{8*self.sixteenth_note}   {2*self.dark}\n {2*self.dark}     {6*self.eighth_note}{6*self.sixteenth_note}     {2*self.dark}\n  {2*self.dark}        {2*self.eighth_note}{2*self.sixteenth_note}        {2*self.dark}\n\n{self.smile +' ' +text}Frums', wait_time)
        def shine(char:str, type:bool, text:str):
            ender_pearl(char, type, self.quarter_beat_time, 2, text)
            ender_pearl(char, type, self.half_quarter_beat_time, 1, text)
            ender_pearl(char, type, self.half_quarter_beat_time, 0, text)
        shine('\xea',0, 'Fun'.ljust(21))
        ender_pearl('.', 0, self.half_beat_time, 0, 'Funding'.ljust(21))
        ender_pearl('\xf7', 0, self.half_beat_time, 0, 'Funding for'.ljust(21))
        ender_pearl('\xea', 0, self.half_beat_time, 0, 'Funding for this'.ljust(21))
        shine('\xf1', 0, 'pro'.ljust(21))
        ender_pearl('\xf7', 0, self.half_beat_time, 0, 'program'.ljust(21))
        ender_pearl('\xea', 0, self.half_beat_time, 0, 'program was'.ljust(21))
        ender_pearl('.', 0, self.half_beat_time, 0, 'program was made'.ljust(21))
        shine('\xea', 0 , 'po'.ljust(21))
        ender_pearl('.', 0, self.half_beat_time, 0, 'possi'.ljust(21))
        ender_pearl('\xf7', 0, self.half_beat_time, 0, 'possible'.ljust(21))
        shine('\xea', 1, 'possible by'.ljust(21))
        shine('\xf1', 1, 'possible by (x2)'.ljust(21))
        ender_pearl('\xf7', 1, self.half_beat_time, 0, 'possible by (x3)'.ljust(21))
        ender_pearl('\xea', 1, self.half_beat_time, 0, 'possible by (x4)'.ljust(21))
        ender_pearl('\xf1', 1, self.half_beat_time, 0, 'possible by (x5)'.ljust(21))
        shine('\xea', 0, 'Fun'.ljust(21))
        ender_pearl('.', 0,self.quarter_beat_time, 2, 'possible by'.ljust(21))
        ender_pearl('.', 0,self.quarter_beat_time, 0, 'possible by (x2)'.ljust(21))
        ender_pearl('\xf7', 0,self.quarter_beat_time, 0, 'possible by (x3)'.ljust(21))
        ender_pearl('\xf7', 0,self.quarter_beat_time, 0, 'possible by (x4)'.ljust(21))
        ender_pearl('\xea', 0, self.half_beat_time, 0, 'Funding'.ljust(21))
        ender_pearl('\xf1', 0, self.half_quarter_beat_time, 2, 'possible by'.ljust(21))
        ender_pearl('\xf1', 0, self.half_quarter_beat_time, 0, 'possible by! (x2)'.ljust(21))
        ender_pearl('\xf7', 0,self.quarter_beat_time, 0, 'possible by!! (x3)'.ljust(21))
        ender_pearl('\xf7', 0,self.quarter_beat_time, 0, 'possible by!!! (x4)'.ljust(21))
        ender_pearl('\xea', 0,self.half_beat_time, 0, 'Funding for'.ljust(21))
        ender_pearl('.', 0,self.half_quarter_beat_time, 0, 'Funding for this'.ljust(21))
        ender_pearl('.', 0,self.half_quarter_beat_time, 0, 'Funding for thii'.ljust(21))
        ender_pearl('.', 0,self.half_quarter_beat_time, 0, 'Funding for thiii'.ljust(21))
        ender_pearl('.', 0,self.half_quarter_beat_time, 0, 'Funding for thiiii'.ljust(21))
        ender_pearl('.', 0,self.half_quarter_beat_time, 0, 'Funding for thiiiii'.ljust(21))
        ender_pearl('.', 0,self.half_quarter_beat_time, 0, 'Funding for thiiiiii'.ljust(21))
        ender_pearl('.', 0,self.half_quarter_beat_time, 0, 'Funding for thiiiiii'.ljust(21))
        shine('\xea', 0, 'pro'.ljust(21))
        ender_pearl('.', 0,self.half_beat_time, 0, 'program'.ljust(21))
        ender_pearl('\xf7', 0,self.quarter_beat_time, 0, 'pro'.ljust(21))
        shine('\xea', 1, 'program'.ljust(21))
        shine('\xf1', 1, 'pro'.ljust(21))
        ender_pearl('\xf1', 1, self.half_quarter_beat_time, 0, 'pro (x2)'.ljust(21))
        ender_pearl('.', 1, self.half_quarter_beat_time, 0, 'pro (x2)'.ljust(21))
        ender_pearl('\xf1', 1, self.half_quarter_beat_time, 0, 'pro (x3)'.ljust(21))
        ender_pearl('.', 1, self.half_quarter_beat_time, 0, 'pro (x3)'.ljust(21))
        ender_pearl('\xf1', 1, self.half_quarter_beat_time, 0, 'pro (x4)'.ljust(21))
        ender_pearl('.', 1, self.half_quarter_beat_time, 0, 'pro (x4)'.ljust(21))
        ender_pearl('\xf1', 1, self.half_quarter_beat_time, 0, 'pro'.ljust(21))
        ender_pearl('.', 1, self.half_quarter_beat_time, 0, 'pro'.ljust(21))
        ender_pearl('\xf1', 1, self.half_quarter_beat_time, 0, 'progr'.ljust(21))
        ender_pearl('.', 1, self.half_quarter_beat_time, 0, 'progr'.ljust(21))
        ender_pearl('\xf1', 1, self.half_quarter_beat_time, 0, 'progr'.ljust(21))
        ender_pearl('.', 1, self.half_quarter_beat_time, 0, 'progr'.ljust(21))
        ender_pearl('\xf1', 1, self.half_quarter_beat_time, 0, 'program'.ljust(21))
        ender_pearl('.', 1, self.half_quarter_beat_time, 0, 'program'.ljust(21))
        shine('\xea', 0, 'Fun'.ljust(21))
        ender_pearl('.', 0, self.half_beat_time, 0, 'Funding'.ljust(21))
        ender_pearl('\xf7', 0, self.half_beat_time, 0, 'Funding for'.ljust(21))
        ender_pearl('\xea', 0, self.half_beat_time, 0, 'possible by'.ljust(21))
        shine('\xf1',  0, 'possible by (x2)'.ljust(21))
        ender_pearl('\xf7', 0, self.half_beat_time, 0, 'program was made'.ljust(21))
        ender_pearl('\xea', 0, self.half_beat_time, 0, 'po'.ljust(21))
        ender_pearl('.', 0, self.half_beat_time, 0, 'possi'.ljust(21))
        shine('\xea', 0, 'possible by'.ljust(21))
        ender_pearl('\xf1', 0, self.half_beat_time+self.quarter_beat_time, 0, 'view'.ljust(21))
        ender_pearl('\xf7', 0, self.half_beat_time, 0, 'viewers'.ljust(21))
        shine('\xea', 1, 'viewers like'.ljust(21))
        shine('\xf1', 1, 'viewers like you.'.ljust(21))
        ender_pearl('\xf7', 0, self.half_beat_time, 0, 'viewers like you.'.ljust(21))

        ender_pearl('\xea', 0, self.half_beat_time, 0, 'viewers like'.ljust(21))
        ender_pearl('.', 0, self.half_beat_time, 0, 'viewers like you.'.ljust(21))
        shine('\xea', 0, 'viewers like you'.ljust(21))

        ender_pearl('.', 0, self.half_beat_time, 0, 'viewers like'.ljust(21))
        ender_pearl('\xf7', 0, self.half_beat_time, 0, 'viewers like you.'.ljust(21))
        ender_pearl('\xea', 0, self.half_beat_time, 0, 'viewers like you.'.ljust(21))

        shine('\xf1', 1, 'viewers like'.ljust(21))
        ender_pearl('\xf7', 0, self.half_beat_time, 0, 'viewers like you.'.ljust(21))
        ender_pearl('\xea', 0, self.half_beat_time, 0, 'viewers like you.'.ljust(21))

        ender_pearl('.', 0, self.half_beat_time, 0, 'viewers like'.ljust(21))
        shine('\xea', 0, 'viewers like you.'.ljust(21))
        ender_pearl('.', 0, self.half_beat_time, 0, 'viewers like you.'.ljust(21))

        ender_pearl('\xf7', 0, self.half_beat_time, 0, 'viewers like'.ljust(21))
        shine('\xea', 1, 'viewers like you.'.ljust(21))
        ender_pearl('\xea', 1, self.half_quarter_beat_time, 0, 'viewers like you.'.ljust(21))

        ender_pearl('.', 1, self.half_quarter_beat_time, 2, 'viewers like you.'.ljust(21))
        ender_pearl('\xf1', 1, self.half_quarter_beat_time, 0, 'viewers like you.'.ljust(21))
        ender_pearl('.', 1, self.half_quarter_beat_time, 0, 'viewers like you.'.ljust(21))
        ender_pearl('\xf1', 1, self.half_quarter_beat_time, 0, 'viewers like you.'.ljust(21))
        ender_pearl('.', 1, self.half_quarter_beat_time, 0, 'viewers like'.ljust(21))
        ender_pearl('\xf1', 1, self.half_quarter_beat_time, 0, 'viewers like'.ljust(21))
        ender_pearl('.', 1, self.half_quarter_beat_time, 0, 'viewers like'.ljust(21))
        ender_pearl('\xf1', 1, self.half_quarter_beat_time, 0, 'viewers like'.ljust(21))
        ender_pearl('.', 1, self.half_quarter_beat_time, 0, 'viewers like you.'.ljust(21))
        ender_pearl('\xf1', 1, self.half_quarter_beat_time, 0, 'viewers like you.'.ljust(21))
        ender_pearl('.', 1, self.half_quarter_beat_time, 0, 'Fu'.ljust(21))
        ender_pearl('\xf1', 1, self.half_quarter_beat_time, 0, 'Fu (x2)'.ljust(21))

        shine('\xea',0, 'Fun'.ljust(21))
        ender_pearl('.', 0, self.half_beat_time, 0, 'Funding'.ljust(21))
        ender_pearl('\xf7', 0, self.half_beat_time, 0, 'Funding for'.ljust(21))
        ender_pearl('\xea', 0, self.half_beat_time, 0, 'Funding for this'.ljust(21))
        shine('\xf1', 0, 'pro'.ljust(21))
        ender_pearl('\xf7', 0, self.half_beat_time, 0, 'program'.ljust(21))
        ender_pearl('\xea', 0, self.half_beat_time, 0, 'program was'.ljust(21))
        ender_pearl('.', 0, self.half_beat_time, 0, 'program was made'.ljust(21))
        shine('\xea', 0 , 'po'.ljust(21))
        ender_pearl('.', 0, self.half_beat_time, 0, 'possi'.ljust(21))
        ender_pearl('\xf7', 0, self.half_beat_time, 0, 'possible'.ljust(21))
        shine('\xea', 1, 'possible by'.ljust(21))
        shine('\xf1', 1, 'possible by (x2)'.ljust(21))
        ender_pearl('\xf7', 1, self.half_beat_time, 0, 'possible by (x3)'.ljust(21))
        ender_pearl('\xea', 1, self.half_beat_time, 0, 'possible by (x4)'.ljust(21))
        ender_pearl('\xf1', 1, self.half_beat_time, 0, 'possible by (x5)'.ljust(21))
        shine('\xea', 0, 'Fun'.ljust(21))
        ender_pearl('.', 0,self.quarter_beat_time, 2, 'possible by'.ljust(21))
        ender_pearl('.', 0,self.quarter_beat_time, 0, 'possible by (x2)'.ljust(21))
        ender_pearl('\xf7', 0,self.quarter_beat_time, 0, 'possible by (x3)'.ljust(21))
        ender_pearl('\xf7', 0,self.quarter_beat_time, 0, 'possible by (x4)'.ljust(21))
        ender_pearl('\xea', 0, self.half_beat_time, 0, 'Funding'.ljust(21))
        ender_pearl('\xf1', 0, self.half_quarter_beat_time, 2, 'possible by'.ljust(21))
        ender_pearl('\xf1', 0, self.half_quarter_beat_time, 0, 'possible by! (x2)'.ljust(21))
        ender_pearl('\xf7', 0,self.quarter_beat_time, 0, 'possible by!! (x3)'.ljust(21))
        ender_pearl('\xf7', 0,self.quarter_beat_time, 0, 'possible by!!! (x4)'.ljust(21))
        ender_pearl('\xea', 0,self.half_beat_time, 0, 'Funding for'.ljust(21))
        ender_pearl('.', 0,self.half_quarter_beat_time, 0, 'Funding for this'.ljust(21))
        ender_pearl('.', 0,self.half_quarter_beat_time, 0, 'Funding for thii'.ljust(21))
        ender_pearl('.', 0,self.half_quarter_beat_time, 0, 'Funding for thiii'.ljust(21))
        ender_pearl('.', 0,self.half_quarter_beat_time, 0, 'Funding for thiiii'.ljust(21))
        ender_pearl('.', 0,self.half_quarter_beat_time, 0, 'Funding for thiiiii'.ljust(21))
        ender_pearl('.', 0,self.half_quarter_beat_time, 0, 'Funding for thiiiiii'.ljust(21))
        ender_pearl('.', 0,self.half_quarter_beat_time, 0, 'Funding for thiiiiii'.ljust(21))
        shine('\xea', 0, 'pro'.ljust(21))
        ender_pearl('.', 0,self.quarter_beat_time, 0, 'program'.ljust(21))
        ender_pearl('\xf7', 0,self.half_beat_time, 0, 'pro'.ljust(21))
        shine('\xea', 1, 'program'.ljust(21))
        shine('\xf1', 1, 'pro'.ljust(21))
        ender_pearl('\xf1', 1, self.half_quarter_beat_time, 0, 'pro (x2)'.ljust(21))
        ender_pearl('.', 1, self.half_quarter_beat_time, 0, 'pro (x2)'.ljust(21))
        ender_pearl('\xf1', 1, self.half_quarter_beat_time, 0, 'pro (x3)'.ljust(21))
        ender_pearl('.', 1, self.half_quarter_beat_time, 0, 'pro (x3)'.ljust(21))
        ender_pearl('\xf1', 1, self.half_quarter_beat_time, 0, 'pro (x4)'.ljust(21))
        ender_pearl('.', 1, self.half_quarter_beat_time, 0, 'pro (x4)'.ljust(21))
        ender_pearl('\xf1', 1, self.half_quarter_beat_time, 0, 'pro'.ljust(21))
        ender_pearl('.', 1, self.half_quarter_beat_time, 0, 'pro'.ljust(21))
        ender_pearl('\xf1', 1, self.half_quarter_beat_time, 0, 'progr'.ljust(21))
        ender_pearl('.', 1, self.half_quarter_beat_time, 0, 'progr'.ljust(21))
        ender_pearl('\xf1', 1, self.half_quarter_beat_time, 0, 'progr'.ljust(21))
        ender_pearl('.', 1, self.half_quarter_beat_time, 0, 'progr'.ljust(21))
        ender_pearl('\xf1', 1, self.half_quarter_beat_time, 0, 'program'.ljust(21))
        ender_pearl('.', 1, self.half_quarter_beat_time, 0, 'program'.ljust(21))
        shine('\xea', 0, 'Fun'.ljust(21))
        ender_pearl('.', 0, self.half_beat_time, 0, 'Funding'.ljust(21))
        ender_pearl('\xf7', 0, self.half_beat_time, 0, 'Funding for'.ljust(21))
        ender_pearl('\xea', 0, self.half_beat_time, 0, 'possible by'.ljust(21))
        shine('\xf1',  0, 'possible by (x2)'.ljust(21))
        ender_pearl('\xf7', 0, self.half_beat_time, 0, 'program was made'.ljust(21))
        ender_pearl('\xea', 0, self.half_beat_time, 0, 'po'.ljust(21))
        ender_pearl('.', 0, self.half_beat_time+self.quarter_beat_time, 0, 'possi'.ljust(21))
        shine('\xea', 0, 'possible by'.ljust(21))
        ender_pearl('\xf1', 0, self.half_beat_time, 0, 'view'.ljust(21))
        ender_pearl('\xf7', 0, self.half_beat_time, 0, 'viewers'.ljust(21))
        shine('\xea', 1, 'viewers like'.ljust(21))
        shine('\xf1', 1, 'viewers like you.'.ljust(21))
        ender_pearl('\xf7', 0, self.half_beat_time, 0, 'viewers like you.'.ljust(21))

        ender_pearl('\xea', 0, self.half_beat_time, 0, 'viewers like'.ljust(21))
        ender_pearl('.', 0, self.half_beat_time, 0, 'viewers like you.'.ljust(21))
        shine('\xea', 0, 'viewers like you'.ljust(21))

        ender_pearl('.', 0, self.half_beat_time, 0, 'viewers like'.ljust(21))
        ender_pearl('\xf7', 0, self.half_beat_time, 0, 'viewers like you.'.ljust(21))
        ender_pearl('\xea', 0, self.half_beat_time, 0, 'viewers like you.'.ljust(21))

        shine('\xf1', 1, 'viewers like'.ljust(21))
        ender_pearl('\xf7', 0, self.half_beat_time, 0, 'viewers like you.'.ljust(21))
        ender_pearl('\xea', 0, self.half_beat_time, 0, 'viewers like you.'.ljust(21))

        ender_pearl('.', 0, self.half_beat_time, 0, 'viewers like'.ljust(21))
        shine('\xea', 0, 'viewers like you.'.ljust(21))
        ender_pearl('.', 0, self.half_beat_time, 0, 'viewers like you.'.ljust(21))

        ender_pearl('\xf1', 0, self.half_quarter_beat_time, 0, 'viewers like you.'.ljust(21))
        self.output(f'Credits\n\n  {self.light*2}{' '*20}{self.light*2}\n {self.light*2}{' '*22}{self.light*2}\n {self.light*2}{' '*7}{self.eighth_note * 4}{self.sixteenth_note*4}{' '*7}{self.light*2}\n{self.light*2}{' '*6}{6*self.eighth_note}{6*self.sixteenth_note}{' '*6}{self.light*2}\n{self.light*2}{' '*6}{6*self.eighth_note}{6*self.sixteenth_note}{' '*6}{self.light*2}\n{self.light*2}{' '*6}{6*self.sixteenth_note}{6*self.eighth_note}{' '*6}{self.light*2}\n{self.light*2}{' '*6}{6*self.sixteenth_note}{6*self.eighth_note}{' '*6}{self.light*2}\n {self.light*2}{' '*7}{self.eighth_note * 4}{self.sixteenth_note*4}{' '*7}{self.light*2}\n {self.light*2}{' '*22}{self.light*2}\n  {self.light*2}{' '*20}{self.light*2}\n\n{self.smile} viewers like you.    Frums', self.half_quarter_beat_time)
        self.output(f'Credits\n\n  {self.light*2}{' '*20}{self.light*2}\n {self.light*2}{' '*22}{self.light*2}\n {self.light*2}{' '*22}{self.light*2}\n{self.light*2}{' '*10}{2*self.eighth_note}{2*self.sixteenth_note}{' '*10}{self.light*2}\n{self.light*2}{' '*8}{4*self.eighth_note}{4*self.sixteenth_note}{' '*8}{self.light*2}\n{self.light*2}{' '*8}{4*self.sixteenth_note}{4*self.eighth_note}{' '*8}{self.light*2}\n{self.light*2}{' '*10}{2*self.sixteenth_note}{2*self.eighth_note}{' '*10}{self.light*2}\n {self.light*2}{' '*22}{self.light*2}\n {self.light*2}{' '*22}{self.light*2}\n  {self.light*2}{' '*20}{self.light*2}\n\n{self.smile} viewers like you.    Frums', self.half_quarter_beat_time)
        self.output(f'Credits{'\n'*13}{self.smile} viewers like you.    Frums', self.quarter_beat_time + self.half_beat_time)

        self.output(f'Credits{'\n'*13}{(self.smile+' Broad').ljust(21)}  Frums', self.half_beat_time)
        self.output(f'Credits{'\n'*13}{(self.smile+' Broadcast').ljust(21)}  Frums', self.half_beat_time)

    def _5(self):
        def _(shine:int, wait_time:float, type:bool, blocks:str, text:str):
            s = self.light if shine == 0 else (self.median if shine == 1 else self.dark)
            if(type == 0):
                self.output(f'Credits\n\n   {s*2} \xc9{'\xcd'*4}\xbb       {self.eighth_note*2}   {s*2}\n  {s*2}  \xba{4*blocks[0]}\xba      {self.eighth_note*4}   {s*2}\n  {s*2}  \xba{4*blocks[0]}\xba       {self.eighth_note*2}    {s*2}\n {s*2}   \xc7\xc4\xc4\xc4\xc4\xb6      {self.eighth_note*4}    {s*2}\n {s*2}   \xba{4*blocks[1]}\xba     {self.eighth_note*6}   {s*2}\n {s*2}   \xba{4*blocks[1]}\xba     {self.eighth_note*6}   {s*2}\n {s*2}   \xc7\xc4\xc4\xc4\xc4\xb6     {self.eighth_note*6}   {s*2}\n  {s*2}  \xba{4*blocks[2]}\xba      {self.eighth_note*4}   {s*2}\n  {s*2}  \xba{4*blocks[2]}\xba      {self.eighth_note*4}   {s*2}\n   {s*2} \xc8\xcd\xcd\xcd\xcd\xbc     {self.eighth_note*2}  {self.eighth_note*2} {s*2}\n\n\xaf {text}Frums', wait_time)
            elif(type == 1):
                self.output(f'Credits\n\n   {s*2} \xc9{'\xcd'*4}\xbb      {self.sixteenth_note*2}    {s*2}\n  {s*2}  \xba{4*blocks[0]}\xba     {self.sixteenth_note*4}    {s*2}\n  {s*2}  \xba{4*blocks[0]}\xba      {self.sixteenth_note*2}     {s*2}\n {s*2}   \xc7\xc4\xc4\xc4\xc4\xb6      {self.sixteenth_note*4}    {s*2}\n {s*2}   \xba{4*blocks[1]}\xba     {self.sixteenth_note*6}   {s*2}\n {s*2}   \xba{4*blocks[1]}\xba   {self.sixteenth_note*2} {self.sixteenth_note*4} {self.sixteenth_note*1}  {s*2}\n {s*2}   \xc7\xc4\xc4\xc4\xc4\xb6      {self.sixteenth_note*4}    {s*2}\n  {s*2}  \xba{4*blocks[2]}\xba     {self.sixteenth_note*2} {self.sixteenth_note*2}   {s*2}\n  {s*2}  \xba{4*blocks[2]}\xba    {self.sixteenth_note*2}  {self.sixteenth_note*2}   {s*2}\n   {s*2} \xc8\xcd\xcd\xcd\xcd\xbc    {self.sixteenth_note*2}   {self.sixteenth_note*2} {s*2}\n\n\xaf {text}Frums', wait_time)

        _(2, self.quarter_beat_time, 0, '\xea..', 'Cor'.ljust(21))
        _(2, self.quarter_beat_time, 0, '...', 'Cor'.ljust(21))
        _(0, self.quarter_beat_time, 0, '..\xf7', 'Corpo'.ljust(21))
        _(0, self.quarter_beat_time, 0, '\xea..', 'Corpora'.ljust(21))
        _(0, self.quarter_beat_time, 0, '...', 'Corpora'.ljust(21))
        _(0, self.quarter_beat_time, 0, '\xea..', 'Corporation'.ljust(21))
        _(0, self.quarter_beat_time, 0, '...', 'Corporation'.ljust(21))
        _(0, self.quarter_beat_time, 0, '\xf7..', 'Corporation'.ljust(21))

        _(2, self.quarter_beat_time, 0, '.\xf1.', 'Cor'.ljust(21))
        _(2, self.quarter_beat_time, 0, '...', 'Cor'.ljust(21))
        _(0, self.quarter_beat_time, 0, '..\xf7', 'Corpo'.ljust(21))
        _(0, self.quarter_beat_time, 0, '\xea..', 'Corpora'.ljust(21))
        _(0, self.quarter_beat_time, 0, '...', 'Corpora'.ljust(21))
        _(0, self.quarter_beat_time, 0, '\xea..', 'Corporation'.ljust(21))
        _(0, self.quarter_beat_time, 0, '...', 'Corporation'.ljust(21))
        _(0, self.quarter_beat_time, 0, '\xf7..', 'Corporation'.ljust(21))

        _(2, self.quarter_beat_time, 0, '\xea..', 'Cor'.ljust(21))
        _(2, self.quarter_beat_time, 0, '...', 'Cor'.ljust(21))
        _(0, self.quarter_beat_time, 0, '..\xf7', 'Corpo'.ljust(21))
        _(0, self.quarter_beat_time, 0, '\xea..', 'Corpora'.ljust(21))
        _(0, self.quarter_beat_time, 0, '...', 'Corpora'.ljust(21))
        _(0, self.quarter_beat_time, 0, '\xea..', 'Corporation'.ljust(21))
        _(0, self.quarter_beat_time, 1, '...', 'Corporation'.ljust(21))
        _(0, self.quarter_beat_time, 1, '\xf7..', 'Corporation'.ljust(21))

        _(2, self.quarter_beat_time, 1, '.\xf1.', 'Cor'.ljust(21))
        _(2, self.quarter_beat_time, 1, '...', 'Cor'.ljust(21))
        _(0, self.quarter_beat_time, 1, '..\xf7', 'Corpo'.ljust(21))
        _(0, self.quarter_beat_time, 1, '\xea..', 'Cor'.ljust(21))
        _(0, self.quarter_beat_time, 1, '...', 'Cor'.ljust(21))
        _(0, self.quarter_beat_time, 1, '\xea..', 'Corpo'.ljust(21))
        _(0, self.half_quarter_beat_time, 1, '.\xf1.', 'Cor'.ljust(21))
        _(0, self.half_quarter_beat_time, 1, '...', 'Cor'.ljust(21))
        _(0, self.half_quarter_beat_time, 1, '.\xf1.', 'Cor (x2)'.ljust(21))
        _(0, self.half_quarter_beat_time, 1, '...', 'Cor (x2)'.ljust(21))
        _(2, self.half_quarter_beat_time, 1, '\xea..', 'Cor (x3)'.ljust(21))
        _(0, self.half_quarter_beat_time, 0, '...', 'Cor (x3)'.ljust(21))
        _(0, self.quarter_beat_time, 0, '..\xf7', 'Corpo'.ljust(21))
        _(0, self.quarter_beat_time, 0, '\xea..', 'Corpora'.ljust(21))
        _(0, self.quarter_beat_time, 0, '...', 'Corpora'.ljust(21))
        _(0, self.quarter_beat_time, 0, '\xea..', 'Corporation'.ljust(21))
        _(0, self.quarter_beat_time, 0, '...', 'Corporation'.ljust(21))
        _(0, self.quarter_beat_time, 0, '..\xf7', 'Corporation'.ljust(21))
        _(2, self.quarter_beat_time, 0, '.\xf1.', 'Cor'.ljust(21))
        _(0, self.quarter_beat_time, 0, '...', 'Cor'.ljust(21))
        _(0, self.quarter_beat_time, 0, '..\xf7', 'Corpo'.ljust(21))
        _(0, self.quarter_beat_time, 0, '\xea..', 'Corpora'.ljust(21))
        _(0, self.quarter_beat_time, 0, '...', 'Corpora'.ljust(21))
        _(0, self.quarter_beat_time, 0, '\xea..', 'Corporation'.ljust(21))
        _(0, self.quarter_beat_time, 0, '...', 'Corporation'.ljust(21))
        _(0, self.quarter_beat_time, 0, '..\xf7', 'Corporation'.ljust(21))
        _(2, self.quarter_beat_time, 0, '\xea..', 'Cor'.ljust(21))
        _(0, self.quarter_beat_time, 0, '...', 'Cor'.ljust(21))
        _(0, self.quarter_beat_time, 0, '..\xf7', 'Corpo'.ljust(21))
        _(0, self.quarter_beat_time, 0, '\xea..', 'Corpora'.ljust(21))
        _(0, self.quarter_beat_time, 0, '...', 'Corpora'.ljust(21))
        _(2, self.quarter_beat_time, 0, '\xea..', 'Corporation'.ljust(21))
        _(0, self.quarter_beat_time, 0, '...', 'Corporation'.ljust(21))
        _(0, self.quarter_beat_time, 1, '...', 'Corporation'.ljust(21))
        _(2, self.quarter_beat_time, 1, '.\xf1.', 'Cor'.ljust(21))
        _(0, self.quarter_beat_time, 1, '...', 'Corporation'.ljust(21))
        _(0, self.quarter_beat_time, 1, '..\xf7', 'Corporation'.ljust(21))
        _(2, self.quarter_beat_time, 1, '.\xea.', 'Cor'.ljust(21))
        _(0, self.quarter_beat_time, 1, '...', 'Corpo'.ljust(21))
        _(0, self.quarter_beat_time, 1, '..\xf7', 'Corpo (x2)'.ljust(21))
        _(2, self.quarter_beat_time, 1, '\xea..', 'Cor'.ljust(21))
        _(0, self.quarter_beat_time, 1, '...', 'Corpo'.ljust(21))
        _(0, self.quarter_beat_time, 1, '\xea..', 'Corpo (x2)'.ljust(21))
        _(0, self.half_quarter_beat_time, 1, '.\xf1.', 'Cor'.ljust(21))
        _(0, self.half_quarter_beat_time, 1, '...', 'Cor'.ljust(21))
        _(0, self.half_quarter_beat_time, 1, '.\xf1.', 'Corpo'.ljust(21))
        _(0, self.half_quarter_beat_time, 1, '...', 'Corpo'.ljust(21))

        _(2, self.quarter_beat_time, 0, '\xea..', 'Cor'.ljust(21))
        _(0, self.quarter_beat_time, 0, '...', 'Cor'.ljust(21))
        _(0, self.half_quarter_beat_time, 0, '.\xf7.', 'Corpo'.ljust(21))
        _(0, self.half_quarter_beat_time, 0, '\xea..', 'Corpora'.ljust(21))
        _(0, self.half_quarter_beat_time, 0, '...', 'Corpora'.ljust(21))
        _(0, self.quarter_beat_time, 0, '\xea  ..', 'Corporation'.ljust(21))
        _(0, self.quarter_beat_time, 0, '...', 'Cor'.ljust(21))
        _(0, self.quarter_beat_time, 0, '..\xf7', 'Cor (x2)'.ljust(21))
        _(2, self.quarter_beat_time, 0, '.\xf1.', 'Cor (x3)'.ljust(21))
        _(0, self.half_quarter_beat_time, 0, '..\xf7', 'Corpo'.ljust(21))
        _(0, self.half_quarter_beat_time, 0, '\xea..', 'Corpora'.ljust(21))
        _(0, self.half_quarter_beat_time, 0, '...', 'Corpora'.ljust(21))
        _(0, self.quarter_beat_time, 0, '\xea..', 'Corporation'.ljust(21))
        _(0, self.quarter_beat_time, 0, '...', 'Cor'.ljust(21))
        _(0, self.quarter_beat_time, 0, '..\xf7', 'Cor (x2)'.ljust(21))
        _(2, self.half_beat_time, 0, '\xea..', 'Cor (x3)'.ljust(21))
        _(0, self.half_quarter_beat_time, 0, '..\xf7', 'Corpo'.ljust(21))
        _(0, self.half_quarter_beat_time, 0, '\xea..', 'Corpora'.ljust(21))
        _(0, self.half_quarter_beat_time, 0, '...', 'Corpora'.ljust(21))
        _(0, self.quarter_beat_time, 0, '\xea..', 'Corporation'.ljust(21))
        _(0, self.quarter_beat_time, 0, '...', 'Corporation'.ljust(21))
        _(0, self.half_quarter_beat_time, 0, '...', 'Cor'.ljust(21))
        _(0, self.half_quarter_beat_time, 1, '..\xf7', 'Cor (x2)'.ljust(21))
        _(2, self.quarter_beat_time, 1, '.\xf1.', 'Cor!'.ljust(21))
        _(0, self.half_quarter_beat_time, 1, '..\xf7', 'Corpor!'.ljust(21))
        _(0, self.half_quarter_beat_time, 1, '\xea..', 'Corpora!'.ljust(21))
        _(0, self.half_quarter_beat_time, 1, '...', 'Corpora!'.ljust(21))
        _(0, self.half_quarter_beat_time, 1, '\xea..', 'Corporation!'.ljust(21))
        _(0, self.half_quarter_beat_time, 1, '...', 'Corporation!'.ljust(21))
        _(0, self.quarter_beat_time, 1, '...', 'Cor!'.ljust(21))
        _(0, self.quarter_beat_time, 1, '..\xf7', 'Cor! (x2)'.ljust(21))
        _(2, self.quarter_beat_time, 0, '\xea..', 'Cor'.ljust(21))
        _(0, self.half_quarter_beat_time, 0, '..\xf7', 'Corpo'.ljust(21))
        _(0, self.half_quarter_beat_time, 0, '\xea..', 'Corpora'.ljust(21))
        _(0, self.half_quarter_beat_time, 0, '...', 'Corpora'.ljust(21))
        _(0, self.quarter_beat_time, 0, '\xea..', 'Corporation'.ljust(21))
        _(0, self.quarter_beat_time, 0, '...', 'Corporation'.ljust(21))
        _(0, self.quarter_beat_time, 0, '...', 'Cor'.ljust(21))
        _(0, self.quarter_beat_time, 0, '..\xf7', 'Cor (x2)'.ljust(21))
        _(2, self.quarter_beat_time, 0, '.\xf1.', 'Cor (x3)'.ljust(21))
        _(0, self.quarter_beat_time, 0, '..\xf7', 'Corpo'.ljust(21))
        _(0, self.quarter_beat_time, 0, '\xea..', 'Corpora'.ljust(21))
        _(0, self.quarter_beat_time, 0, '...', 'Corpora'.ljust(21))
        _(0, self.quarter_beat_time, 0, '\xea..', 'Corporation'.ljust(21))
        _(0, self.quarter_beat_time, 0, '...', 'Corporation'.ljust(21))
        _(0, self.quarter_beat_time, 0, '...', 'Cor'.ljust(21))   
        _(0, self.quarter_beat_time, 0, '..\xf7', 'Cor (x2)'.ljust(21))
        _(2, self.quarter_beat_time, 0, '.\xf1.', 'Cor (x3)'.ljust(21))
        _(0, self.quarter_beat_time, 0, '..\xf7', 'Corpo'.ljust(21))
        _(0, self.quarter_beat_time, 0, '\xea..', 'Corpora'.ljust(21))
        _(0, self.quarter_beat_time, 0, '...', 'Corpora'.ljust(21))
        _(0, self.quarter_beat_time, 0, '\xea..', 'Corporation'.ljust(21))
        _(0, self.quarter_beat_time, 0, '...', 'Cor'.ljust(21))   
        _(0, self.quarter_beat_time, 0, '..\xf7', 'Cor (x2)'.ljust(21))
        for i in range(4):
            _(2, self.quarter_beat_time, 0, '.\xf1.', 'Cor'.ljust(21))
            _(0, self.quarter_beat_time, 0, '..\xf7', 'Corpo'.ljust(21))
            _(0, self.quarter_beat_time, 0, '\xea..', 'Corpora'.ljust(21))
        self.output(f'Credits{'\n'*13}\xaf {'Corporat'.ljust(21)}Frums', self.half_quarter_beat_time)
        self.output(f'Credits{'\n'*13}\xaf {'Corporati'.ljust(21)}Frums', self.half_quarter_beat_time)
        self.output(f'Credits{'\n'*13}\xaf {'Corporatio'.ljust(21)}Frums', self.half_quarter_beat_time)
        self.output(f'Credits{'\n'*13}\xaf {'Corporation'.ljust(21)}Frums', self.half_quarter_beat_time)
        self.output(f'Credits{'\n'*13}\xaf {'Corporation'.ljust(21)}Frums', self.half_beat_time)

    def _6(self):
        cop = "Corporation"
        inv_cop = f"uo{chr(0x2c6)+chr(0x2021)+chr(0x2030)+chr(0x2020)}od{chr(0x2020)}o{chr(0x2026)}"
        def _(length:int, type:bool, block:list, shine:int, wait_time, repeat:int =1):
            s = self.light if shine == 0 else (self.median if shine == 1 else self.dark)
            r = '\xab' if repeat == 2 else '\xac' if repeat == 3 else ''
            if(type==0):
                self.output(f'Credits{(((f'\xa6x{r}\xa7 ')if repeat != 1 else '') + inv_cop[11-length:]).rjust(19)} \xae\n\n   {s*2}\xc9{'\xcd'*9}\xd1{'\xcd'*7}\xbb{s*2}\n  {s*2} \xba         \x7c{block[0]}\xba {s*2}\n  {s*2} \xba   {self.eighth_note*2}    \x7c{block[1]}\xba {s*2}\n {s*2}  \xba  {self.eighth_note*4}   \x7c{block[2]}\xba  {s*2}\n {s*2}  \xba   {self.eighth_note*2}    \x7c{block[3]}\xba  {s*2}\n {s*2}  \xba  {self.eighth_note*4} {self.eighth_note} \x7c{block[4]}\xba  {s*2}\n {s*2}  \xba {self.eighth_note*6}  \x7c{block[5]}\xba  {s*2}\n  {s*2} \xba {self.eighth_note*5}   \x7c{block[6]}\xba {s*2}\n  {s*2} \xba{'\xdf'*9}\x7c{block[7]}\xba {s*2}\n   {s*2}\xc8{'\xcd'*9}\xcf{'\xcd'*7}\xbc{s*2}\n\n\xaf {(cop[:length]+((f' ({repeat}x)')if repeat != 1 else '')).ljust(21)}Frums', wait_time)
            elif(type == 1):   
                self.output(f'Credits{(((f'\xa6x{r}\xa7 ')if repeat != 1 else '') + inv_cop[11-length:]).rjust(19)} \xae\n\n   {s*2}\xc9{'\xcd'*7}\xd1{'\xcd'*9}\xbb{s*2}\n  {s*2} \xba{block[0]}\x7c         \xba {s*2}\n  {s*2} \xba{block[1]}\x7c    {self.sixteenth_note*2}   \xba {s*2}\n {s*2}  \xba{block[2]}\x7c   {self.sixteenth_note*4}  \xba  {s*2}\n {s*2}  \xba{block[3]}\x7c    {self.sixteenth_note*2}   \xba  {s*2}\n {s*2}  \xba{block[4]}\x7c {self.sixteenth_note} {self.sixteenth_note*4}  \xba  {s*2}\n {s*2}  \xba{block[5]}\x7c  {self.sixteenth_note*6} \xba  {s*2}\n  {s*2} \xba{block[6]}\x7c   {self.sixteenth_note*5} \xba {s*2}\n  {s*2} \xba{block[7]}\x7c{'\xdf'*9}\xba {s*2}\n   {s*2}\xc8{'\xcd'*7}\xcf{'\xcd'*9}\xbc{s*2}\n\n\xaf {(cop[:length]+((f' ({repeat}x)')if repeat != 1 else '')).ljust(21)}Frums', wait_time)

        for i in range(4):
            _(3, 0, ['..\xea\xea\xea..', '.\xea...\xea.', '\xea.....\xea', '\xea.....\xea', '.\xea...\xea.', '.\xea...\xea.', '\xea\xea...\xea\xea', 'K i c k'], 2, self.half_quarter_beat_time, 3 if i != 0 else 1)
            _(3, 0, ['..\xea\xea\xea..', '.\xea...\xea.', '\xea.....\xea', '\xea.....\xea', '.\xea...\xea.', '.\xea...\xea.', '\xea\xea...\xea\xea', 'K i c k'], 0, self.half_quarter_beat_time, 3 if i != 0 else 1)
            _(5, 0, ['.......' if x!=7 else 'N o n e' for x in range(8) ], 0, self.quarter_beat_time)
            _(7, 0, ['.......', f'.{'\xf7'*3}.{'\xf7'*2}', f'{'\xf7'*2}.{'\xf7'*3}.', '.......', f'.{'\xf7'*3}.{'\xf7'*2}', f'{'\xf7'*2}.{'\xf7'*3}.', '.......', 'R i d e'], 0, self.quarter_beat_time)
            _(3, 0, ['..\xea\xea\xea..', '.\xea...\xea.', '\xea.....\xea', '\xea.....\xea', '.\xea...\xea.', '.\xea...\xea.', '\xea\xea...\xea\xea', 'K i c k'], 0, self.quarter_beat_time)
            _(5, 0, ['.......' if x!=7 else 'N o n e' for x in range(8) ], 0, self.quarter_beat_time)
            _(3, 0, ['..\xea\xea\xea..', '.\xea...\xea.', '\xea.....\xea', '\xea.....\xea', '.\xea...\xea.', '.\xea...\xea.', '\xea\xea...\xea\xea', 'K i c k'], 0, self.quarter_beat_time)
            _(5, 0, ['.......' if x!=7 else 'N o n e' for x in range(8) ], 0, self.quarter_beat_time)
            _(7, 0, ['.......', f'.{'\xf7'*3}.{'\xf7'*2}', f'{'\xf7'*2}.{'\xf7'*3}.', '.......', f'.{'\xf7'*3}.{'\xf7'*2}', f'{'\xf7'*2}.{'\xf7'*3}.', '.......', 'R i d e'], 0, self.quarter_beat_time)
            _(3, 0, ['...\xf1...' if x!=2 and x!=7 else(f'.{'\xf1'*5}.' if x==2 or x==6 else 'S h o t' ) for x in range(8)], 2, self.half_quarter_beat_time)
            _(3, 0, ['...\xf1...' if x!=2 and x!=7 else(f'.{'\xf1'*5}.' if x==2 or x==6 else 'S h o t' ) for x in range(8)], 0, self.half_quarter_beat_time)
            _(5, 0, ['.......' if x!=7 else 'N o n e' for x in range(8) ], 0, self.quarter_beat_time)
            _(7, 0, ['.......', f'.{'\xf7'*3}.{'\xf7'*2}', f'{'\xf7'*2}.{'\xf7'*3}.', '.......', f'.{'\xf7'*3}.{'\xf7'*2}', f'{'\xf7'*2}.{'\xf7'*3}.', '.......', 'R i d e'], 0, self.quarter_beat_time)
            _(3, 0, ['..\xea\xea\xea..', '.\xea...\xea.', '\xea.....\xea', '\xea.....\xea', '.\xea...\xea.', '.\xea...\xea.', '\xea\xea...\xea\xea', 'K i c k'], 0, self.quarter_beat_time)
            _(5, 0, ['.......' if x!=7 else 'N o n e' for x in range(8) ], 0, self.quarter_beat_time)
            _(3, 0, ['..\xea\xea\xea..', '.\xea...\xea.', '\xea.....\xea', '\xea.....\xea', '.\xea...\xea.', '.\xea...\xea.', '\xea\xea...\xea\xea', 'K i c k'], 0, self.quarter_beat_time)
            _(5, 0, ['.......' if x!=7 else 'N o n e' for x in range(8) ], 0, self.quarter_beat_time)
            _(3, 0, ['..\xea\xea\xea..', '.\xea...\xea.', '\xea.....\xea', '\xea.....\xea', '.\xea...\xea.', '.\xea...\xea.', '\xea\xea...\xea\xea', 'K i c k'], 0, self.quarter_beat_time)
            _(5, 0, ['.......' if x!=7 else 'N o n e' for x in range(8) ], 0, self.quarter_beat_time)
            _(7, 0, ['.......', f'.{'\xf7'*3}.{'\xf7'*2}', f'{'\xf7'*2}.{'\xf7'*3}.', '.......', f'.{'\xf7'*3}.{'\xf7'*2}', f'{'\xf7'*2}.{'\xf7'*3}.', '.......', 'R i d e'], 0, self.quarter_beat_time)
            _(3, 0, ['..\xea\xea\xea..', '.\xea...\xea.', '\xea.....\xea', '\xea.....\xea', '.\xea...\xea.', '.\xea...\xea.', '\xea\xea...\xea\xea', 'K i c k'], 2, self.half_quarter_beat_time)
            _(3, 0, ['..\xea\xea\xea..', '.\xea...\xea.', '\xea.....\xea', '\xea.....\xea', '.\xea...\xea.', '.\xea...\xea.', '\xea\xea...\xea\xea', 'K i c k'], 0, self.half_quarter_beat_time)
            _(5, 0, ['.......' if x!=7 else 'N o n e' for x in range(8) ], 0, self.quarter_beat_time)
            _(7, 0, ['.......', f'.{'\xf7'*3}.{'\xf7'*2}', f'{'\xf7'*2}.{'\xf7'*3}.', '.......', f'.{'\xf7'*3}.{'\xf7'*2}', f'{'\xf7'*2}.{'\xf7'*3}.', '.......', 'R i d e'], 0, self.quarter_beat_time)
            _(3, 0, ['..\xea\xea\xea..', '.\xea...\xea.', '\xea.....\xea', '\xea.....\xea', '.\xea...\xea.', '.\xea...\xea.', '\xea\xea...\xea\xea', 'K i c k'], 0, self.quarter_beat_time)
            _(5, 0, ['.......' if x!=7 else 'N o n e' for x in range(8) ], 0, self.quarter_beat_time)
            _(3, 0, ['..\xea\xea\xea..', '.\xea...\xea.', '\xea.....\xea', '\xea.....\xea', '.\xea...\xea.', '.\xea...\xea.', '\xea\xea...\xea\xea', 'K i c k'], 0, self.quarter_beat_time)
            _(5, 1, ['.......' if x!=7 else 'N o n e' for x in range(8) ], 0, self.quarter_beat_time) #反转
            _(7, 1, ['.......', f'.{'\xf7'*3}.{'\xf7'*2}', f'{'\xf7'*2}.{'\xf7'*3}.', '.......', f'.{'\xf7'*3}.{'\xf7'*2}', f'{'\xf7'*2}.{'\xf7'*3}.', '.......', 'R i d e'], 0, self.quarter_beat_time)
            _(3, 1, ['...\xf1...' if x!=2 and x!=7 else(f'.{'\xf1'*5}.' if x==2 or x==6 else 'S h o t' ) for x in range(8)], 2, self.half_quarter_beat_time)
            _(3, 1, ['...\xf1...' if x!=2 and x!=7 else(f'.{'\xf1'*5}.' if x==2 or x==6 else 'S h o t' ) for x in range(8)], 0, self.half_quarter_beat_time)
            _(5, 1, ['.......' if x!=7 else 'N o n e' for x in range(8) ], 0, self.quarter_beat_time)
            _(7, 1, ['.......', f'.{'\xf7'*3}.{'\xf7'*2}', f'{'\xf7'*2}.{'\xf7'*3}.', '.......', f'.{'\xf7'*3}.{'\xf7'*2}', f'{'\xf7'*2}.{'\xf7'*3}.', '.......', 'R i d e'], 0, self.quarter_beat_time)
            _(3, 1, ['...\xf1...' if x!=2 and x!=7 else(f'.{'\xf1'*5}.' if x==2 or x==6 else 'S h o t' ) for x in range(8)], 2, self.half_quarter_beat_time)
            _(3, 1, ['...\xf1...' if x!=2 and x!=7 else(f'.{'\xf1'*5}.' if x==2 or x==6 else 'S h o t' ) for x in range(8)], 0, self.half_quarter_beat_time)
            if(i==3):break
            _(3, 1, ['...\xf1...' if x!=2 and x!=7 else(f'.{'\xf1'*5}.' if x==2 or x==6 else 'S h o t' ) for x in range(8)], 2, self.half_quarter_beat_time, 2)
            _(3, 1, ['...\xf1...' if x!=2 and x!=7 else(f'.{'\xf1'*5}.' if x==2 or x==6 else 'S h o t' ) for x in range(8)], 0, self.half_quarter_beat_time, 2)

    def _7(self):
        def ender_pearl(char:str, type:bool, wait_time:float, text:list, shine:int =0, hide:bool =0):
            s = self.light if shine == 0 else (self.median if shine == 1 else self.dark)
            if type ==0:
                self.output(f'Credits{text[0]}{'\xae' if hide ==0 else ' '}\n\n  {s*2}        {2*self.eighth_note}{2*self.sixteenth_note}        {s*2}\n {s*2}      {6*self.eighth_note}{6*self.sixteenth_note}    {s*2}\n {s*2}   {8*self.eighth_note}{8*self.sixteenth_note}   {s*2}\n{s*2}    {6*self.eighth_note}{4*char}{6*self.sixteenth_note}    {s*2}\n{s*2}  {6*self.eighth_note}{8*char}{6*self.sixteenth_note}  {s*2}\n{s*2}  {6*self.sixteenth_note}{8*char}{6*self.eighth_note}  {s*2}\n{s*2}    {6*self.sixteenth_note}{4*char}{6*self.eighth_note}    {s*2}\n {s*2}   {8*self.sixteenth_note}{8*self.eighth_note}   {s*2}\n {s*2}     {6*self.sixteenth_note}{6*self.eighth_note}     {s*2}\n  {s*2}        {2*self.sixteenth_note}{2*self.eighth_note}        {s*2}\n\n{'\xaf' if hide ==0 else ' '}{text[1]}Frums', wait_time)
            elif type ==1:
                self.output(f'Credits{text[0]}{'\xae' if hide ==0 else ' '}\n\n  {s*2}        {2*self.sixteenth_note}{2*self.eighth_note}        {s*2}\n {s*2}      {6*self.sixteenth_note}{6*self.eighth_note}    {s*2}\n {s*2}   {8*self.sixteenth_note}{8*self.eighth_note}   {s*2}\n{s*2}    {6*self.sixteenth_note}{4*char}{6*self.eighth_note}    {s*2}\n{s*2}  {6*self.sixteenth_note}{8*char}{6*self.eighth_note}  {s*2}\n{s*2}  {6*self.eighth_note}{8*char}{6*self.sixteenth_note}  {s*2}\n{s*2}    {6*self.eighth_note}{4*char}{6*self.sixteenth_note}    {s*2}\n {s*2}   {8*self.eighth_note}{8*self.sixteenth_note}   {s*2}\n {s*2}     {6*self.eighth_note}{6*self.sixteenth_note}     {s*2}\n  {s*2}        {2*self.eighth_note}{2*self.sixteenth_note}        {s*2}\n\n{'\xaf' if hide ==0 else ' '}{text[1]}Frums', wait_time)
        inv_tion = f"uo{chr(0x2c6)+chr(0x2021)}"
        inv_cop = f"uo{chr(0x2c6)+chr(0x2021)+chr(0x2030)+chr(0x2020)}od{chr(0x2020)}o{chr(0x2026)}"
        cop = "Corporation"
        for i in range(12):
            self.output(f'Credits{(i*chr(0x2021)).rjust(11)+inv_cop[3:]} \xae{'\n'*13}\xaf {(cop[:8]+i*'t').ljust(21)}Frums', self.half_quarter_beat_time/2)
            if(i==7):
                self.output(f'Credits{(i*chr(0x2021)).rjust(11)+inv_cop[3:]+self.light}\xae{'\n'*13}\xaf{(self.light+cop[:8]+i*'t').ljust(22)}Frums', self.half_quarter_beat_time/2)
            if(i==8):
                self.output(f'Credits{(i*chr(0x2021)).rjust(11)+inv_cop[3:-1]+self.light*2}\xae{'\n'*13}\xaf{(self.light*2+cop[1:8]+i*'t').ljust(22)}Frums', self.half_quarter_beat_time/2)
        self.output(f'Credits{(12*chr(0x2021)).rjust(13)+self.light*7}\xae{'\n'*13}\xaf{(self.light*7+12*'t').ljust(24)}Frums', self.half_quarter_beat_time/2)
        ender_pearl('\xea', 0, self.quarter_beat_time, [f'{(inv_tion + self.dark*8).rjust(20)}', f'{self.dark*8}tion'.ljust(22)], shine=2)
        ender_pearl('\xea', 0, self.quarter_beat_time, [f'{(self.median*8).rjust(20)}', f'{self.median*8}'.ljust(22)], hide=1, shine=1)
        ender_pearl('.', 0, self.quarter_beat_time, [f'{(inv_tion + self.light*8).rjust(20)}', f'{self.light*8}tion'.ljust(22)])
        ender_pearl('.', 0, self.quarter_beat_time, [f'{(self.median*8).rjust(20)}', f'{self.median*8}'.ljust(22)], hide=1)
        ender_pearl('\xf7', 0, self.quarter_beat_time, [f'{(inv_tion + self.dark*8).rjust(20)}', f'{self.dark*8}tion'.ljust(22)])
        ender_pearl('\xf7', 0, self.quarter_beat_time, [f'{(self.median*8).rjust(20)}', f'{self.median*8}'.ljust(22)], hide=1)
        ender_pearl('\xea', 0, self.quarter_beat_time, [f'{(inv_tion + self.light*8).rjust(20)}', f'{self.light*8}tion'.ljust(22)])
        ender_pearl('\xea', 0, self.quarter_beat_time, [f'{(self.median*8).rjust(20)}', f'{self.median*8}'.ljust(22)], hide=1)
        ender_pearl('.', 0, self.quarter_beat_time, [f'{(inv_tion+' ' + self.dark*7).rjust(20)}', f'{self.dark*7} tion'.ljust(22)], shine=2)
        ender_pearl('.', 0, self.quarter_beat_time, [f'{(self.median*7).rjust(20)}', f'{self.median*7}'.ljust(22)], hide=1, shine=1)
        ender_pearl('\xf7', 0, self.quarter_beat_time, [f'{(inv_tion+' '  + self.light*7).rjust(20)}', f'{self.light*7} tion'.ljust(22)])
        ender_pearl('\xf7', 0, self.quarter_beat_time, [f'{(self.median*7).rjust(20)}', f'{self.median*7}'.ljust(22)], hide=1)
        ender_pearl('\xea', 0, self.quarter_beat_time, [f'{(inv_tion+' '  + self.dark*7).rjust(20)}', f'{self.dark*7} tion'.ljust(22)])
        ender_pearl('\xea', 0, self.quarter_beat_time, [f'{(self.median*7).rjust(20)}', f'{self.median*7}'.ljust(22)], hide=1)
        ender_pearl('.', 0, self.quarter_beat_time, [f'{(inv_tion+' '  + self.light*7).rjust(20)}', f'{self.light*7} tion'.ljust(22)])
        ender_pearl('.', 0, self.quarter_beat_time, [f'{(self.median*7).rjust(20)}', f'{self.median*7}'.ljust(22)], hide=1)
        ender_pearl('\xea', 0, self.quarter_beat_time, [f'{(inv_tion[:3]+'   '+self.dark*6).rjust(20)}', f'{self.dark*6}   ion'.ljust(22)], shine=2)
        ender_pearl('\xea', 0, self.quarter_beat_time, [f'{(self.median*6).rjust(20)}', f'{self.median*6}'.ljust(22)], hide=1, shine=1)
        ender_pearl('.', 0, self.quarter_beat_time, [f'{(inv_tion[:3]+'   '+self.light*6).rjust(20)}', f'{self.light*6}   ion'.ljust(22)])
        ender_pearl('.', 0, self.quarter_beat_time, [f'{(self.median*6).rjust(20)}', f'{self.median*6}'.ljust(22)], hide=1)
        ender_pearl('\xf7', 0, self.quarter_beat_time, [f'{(inv_tion[:3]+'   '+self.dark*6).rjust(20)}', f'{self.dark*6}   ion'.ljust(22)])
        ender_pearl('\xf7', 0, self.quarter_beat_time, [f'{(self.median*6).rjust(20)}', f'{self.median*6}'.ljust(22)], hide=1)
        ender_pearl('\xea', 1, self.quarter_beat_time, [f'{(inv_tion[:3]+'   '+self.light*6).rjust(20)}', f'{self.light*6}   ion'.ljust(22)], shine=2)
        ender_pearl('\xea', 1, self.quarter_beat_time, [f'{(self.median*6).rjust(20)}', f'{self.median*6}'.ljust(22)], hide=1, shine=1)
        for i in range(8):
            ender_pearl('\xf1', 1, self.half_quarter_beat_time, [f'{(inv_tion[:3]+'    '+self.light*5).rjust(20)}', f'{self.light*5}    ion'.ljust(22)] if i%2==0 else [f'{(self.median*5).rjust(20)}', f'{self.median*5}'.ljust(22)], shine=2 if i==0 else 0)
            ender_pearl('.', 1, self.half_quarter_beat_time, [f'{(self.median*5).rjust(20)}', f'{self.median*5}'.ljust(22)] if i%2 == 0 else [f'{(inv_tion[:3]+'    '+self.light*5).rjust(20)}', f'{self.light*5}    ion'.ljust(22)], hide=1, shine=1 if i==0 else 0)
        ender_pearl('\xea', 0, self.quarter_beat_time, [f'{('uo'+ ' '*6 + self.dark*4).rjust(20)}', f'{self.dark*4}      on'.ljust(22)], shine=2)
        ender_pearl('\xea', 0, self.quarter_beat_time, [f'{(self.median*4).rjust(20)}', f'{self.median*4}'.ljust(22)], hide=1, shine=1)
        ender_pearl('.', 0, self.quarter_beat_time, [f'{('uo'+ ' '*6 + self.light*4).rjust(20)}', f'{self.light*4}      on'.ljust(22)])
        ender_pearl('.', 0, self.quarter_beat_time, [f'{(self.median*4).rjust(20)}', f'{self.median*4}'.ljust(22)], hide=1)
        ender_pearl('\xf7', 0, self.quarter_beat_time, [f'{('uo'+ ' '*6 + self.dark*4).rjust(20)}', f'{self.dark*4}      on'.ljust(22)])
        ender_pearl('\xf7', 0, self.quarter_beat_time, [f'{(self.median*4).rjust(20)}', f'{self.median*4}'.ljust(22)], hide=1)
        ender_pearl('\xea', 0, self.quarter_beat_time, [f'{('uo'+ ' '*6 + self.light*4).rjust(20)}', f'{self.light*4}      on'.ljust(22)])
        ender_pearl('\xea', 0, self.quarter_beat_time, [f'{(self.median*4).rjust(20)}', f'{self.median*4}'.ljust(22)], hide=1)
        ender_pearl('.', 0, self.quarter_beat_time, [f'{('uo'+' '*7 + self.dark*3).rjust(20)}', f'{self.dark*3}       on'.ljust(22)], shine=2)
        ender_pearl('.', 0, self.quarter_beat_time, [f'{(self.median*3).rjust(20)}', f'{self.median*3}'.ljust(22)], hide=1, shine=1)
        ender_pearl('\xf7', 0, self.quarter_beat_time, [f'{('uo'+' '*7  + self.light*3).rjust(20)}', f'{self.light*3}       on'.ljust(22)])
        ender_pearl('\xf7', 0, self.quarter_beat_time, [f'{(self.median*3).rjust(20)}', f'{self.median*3}'.ljust(22)], hide=1)
        ender_pearl('\xea', 0, self.quarter_beat_time, [f'{('uo'+' '*7  + self.dark*3).rjust(20)}', f'{self.dark*3}       on'.ljust(22)])
        ender_pearl('\xea', 0, self.quarter_beat_time, [f'{(self.median*3).rjust(20)}', f'{self.median*3}'.ljust(22)], hide=1)
        ender_pearl('.', 0, self.quarter_beat_time, [f'{('uo'+' '*7  + self.light*3).rjust(20)}', f'{self.light*3}       on'.ljust(22)])
        ender_pearl('.', 0, self.quarter_beat_time, [f'{(self.median*3).rjust(20)}', f'{self.median*3}'.ljust(22)], hide=1)
        ender_pearl('\xea', 0, self.quarter_beat_time, [f'{('u         '+self.dark*2).rjust(20)}', f'{self.dark*2}         n'.ljust(22)], shine=2)
        ender_pearl('\xea', 0, self.quarter_beat_time, [f'{(self.median*2).rjust(20)}', f'{self.median*2}'.ljust(22)], hide=1, shine=1)
        ender_pearl('.', 0, self.quarter_beat_time,  [f'{('u         '+self.light*2).rjust(20)}', f'{self.light*2}         n'.ljust(22)])
        ender_pearl('.', 0, self.quarter_beat_time, [f'{(self.median*2).rjust(20)}', f'{self.median*2}'.ljust(22)], hide=1)
        ender_pearl('\xf7', 0, self.quarter_beat_time, [f'{('u         '+self.dark*2).rjust(20)}', f'{self.dark*2}         n'.ljust(22)])
        ender_pearl('\xf7', 0, self.quarter_beat_time, [f'{(self.median*2).rjust(20)}', f'{self.median*2}'.ljust(22)], hide=1)
        ender_pearl('\xea', 1, self.quarter_beat_time, [f'{('u         '+self.light*2).rjust(20)}', f'{self.light*2}         n'.ljust(22)], shine=2)
        ender_pearl('\xea', 1, self.quarter_beat_time, [f'{(self.median*2).rjust(20)}', f'{self.median*2}'.ljust(22)], hide=1, shine=1)
        for i in range(8):
            ender_pearl('\xf1', 1, self.half_quarter_beat_time, [f'{('u          '+self.light).rjust(20)}', f'{self.light}          n'.ljust(22)] if i%2==0 else [f'{(self.median).rjust(20)}', f'{self.median}'.ljust(22)], shine=2 if i==0 else 0)
            ender_pearl('.', 1, self.half_quarter_beat_time, [f'{(self.median).rjust(20)}', f'{self.median}'.ljust(22)] if i%2 == 0 else [f'{('u          '+self.light).rjust(20)}', f'{self.light}          n'.ljust(22)], hide=1, shine=1 if i==0 else 0)

    def _8(self):
        def ender_pearl(char:str, type:bool, wait_time:float, shine:int = 0):
            if type ==0:
                if shine ==0:
                    self.output(f'Credits\n\n  {2*self.light}        {2*self.eighth_note}{2*self.sixteenth_note}        {2*self.light}\n {2*self.light}     {6*self.eighth_note}{6*self.sixteenth_note}     {2*self.light}\n {2*self.light}   {8*self.eighth_note}{8*self.sixteenth_note}   {2*self.light}\n{2*self.light}    {6*self.eighth_note}{4*char}{6*self.sixteenth_note}    {2*self.light}\n{2*self.light}  {6*self.eighth_note}{8*char}{6*self.sixteenth_note}  {2*self.light}\n{2*self.light}  {6*self.sixteenth_note}{8*char}{6*self.eighth_note}  {2*self.light}\n{2*self.light}    {6*self.sixteenth_note}{4*char}{6*self.eighth_note}    {2*self.light}\n {2*self.light}   {8*self.sixteenth_note}{8*self.eighth_note}   {2*self.light}\n {2*self.light}     {6*self.sixteenth_note}{6*self.eighth_note}     {2*self.light}\n  {2*self.light}        {2*self.sixteenth_note}{2*self.eighth_note}        {2*self.light}\n\n                       Frums', wait_time)
                elif shine ==1:
                    self.output(f'Credits\n\n  {2*self.median}        {2*self.eighth_note}{2*self.sixteenth_note}        {2*self.median}\n {2*self.median}     {6*self.eighth_note}{6*self.sixteenth_note}     {2*self.median}\n {2*self.median}   {8*self.eighth_note}{8*self.sixteenth_note}   {2*self.median}\n{2*self.median}    {6*self.eighth_note}{4*char}{6*self.sixteenth_note}    {2*self.median}\n{2*self.median}  {6*self.eighth_note}{8*char}{6*self.sixteenth_note}  {2*self.median}\n{2*self.median}  {6*self.sixteenth_note}{8*char}{6*self.eighth_note}  {2*self.median}\n{2*self.median}    {6*self.sixteenth_note}{4*char}{6*self.eighth_note}    {2*self.median}\n {2*self.median}   {8*self.sixteenth_note}{8*self.eighth_note}   {2*self.median}\n {2*self.median}     {6*self.sixteenth_note}{6*self.eighth_note}     {2*self.median}\n  {2*self.median}        {2*self.sixteenth_note}{2*self.eighth_note}        {2*self.median}\n\n                       Frums', wait_time)
                elif shine ==2:
                    self.output(f'Credits\n\n  {2*self.dark}        {2*self.eighth_note}{2*self.sixteenth_note}        {2*self.dark}\n {2*self.dark}     {6*self.eighth_note}{6*self.sixteenth_note}     {2*self.dark}\n {2*self.dark}   {8*self.eighth_note}{8*self.sixteenth_note}   {2*self.dark}\n{2*self.dark}    {6*self.eighth_note}{4*char}{6*self.sixteenth_note}    {2*self.dark}\n{2*self.dark}  {6*self.eighth_note}{8*char}{6*self.sixteenth_note}  {2*self.dark}\n{2*self.dark}  {6*self.sixteenth_note}{8*char}{6*self.eighth_note}  {2*self.dark}\n{2*self.dark}    {6*self.sixteenth_note}{4*char}{6*self.eighth_note}    {2*self.dark}\n {2*self.dark}   {8*self.sixteenth_note}{8*self.eighth_note}   {2*self.dark}\n {2*self.dark}     {6*self.sixteenth_note}{6*self.eighth_note}     {2*self.dark}\n  {2*self.dark}        {2*self.sixteenth_note}{2*self.eighth_note}        {2*self.dark}\n\n                       Frums', wait_time)
            elif type ==1:
                if shine ==0:
                    self.output(f'Credits\n\n  {2*self.light}        {2*self.sixteenth_note}{2*self.eighth_note}        {2*self.light}\n {2*self.light}     {6*self.sixteenth_note}{6*self.eighth_note}     {2*self.light}\n {2*self.light}   {8*self.sixteenth_note}{8*self.eighth_note}   {2*self.light}\n{2*self.light}    {6*self.sixteenth_note}{4*char}{6*self.eighth_note}    {2*self.light}\n{2*self.light}  {6*self.sixteenth_note}{8*char}{6*self.eighth_note}  {2*self.light}\n{2*self.light}  {6*self.eighth_note}{8*char}{6*self.sixteenth_note}  {2*self.light}\n{2*self.light}    {6*self.eighth_note}{4*char}{6*self.sixteenth_note}    {2*self.light}\n {2*self.light}   {8*self.eighth_note}{8*self.sixteenth_note}   {2*self.light}\n {2*self.light}     {6*self.eighth_note}{6*self.sixteenth_note}     {2*self.light}\n  {2*self.light}        {2*self.eighth_note}{2*self.sixteenth_note}        {2*self.light}\n\n                       Frums', wait_time)
                elif shine ==1:
                    self.output(f'Credits\n\n  {2*self.median}        {2*self.sixteenth_note}{2*self.eighth_note}        {2*self.median}\n {2*self.median}     {6*self.sixteenth_note}{6*self.eighth_note}     {2*self.median}\n {2*self.median}   {8*self.sixteenth_note}{8*self.eighth_note}   {2*self.median}\n{2*self.median}    {6*self.sixteenth_note}{4*char}{6*self.eighth_note}    {2*self.median}\n{2*self.median}  {6*self.sixteenth_note}{8*char}{6*self.eighth_note}  {2*self.median}\n{2*self.median}  {6*self.eighth_note}{8*char}{6*self.sixteenth_note}  {2*self.median}\n{2*self.median}    {6*self.eighth_note}{4*char}{6*self.sixteenth_note}    {2*self.median}\n {2*self.median}   {8*self.eighth_note}{8*self.sixteenth_note}   {2*self.median}\n {2*self.median}     {6*self.eighth_note}{6*self.sixteenth_note}     {2*self.median}\n  {2*self.median}        {2*self.eighth_note}{2*self.sixteenth_note}        {2*self.median}\n\n                       Frums', wait_time)
                elif shine ==2:
                    self.output(f'Credits\n\n  {2*self.dark}        {2*self.sixteenth_note}{2*self.eighth_note}        {2*self.dark}\n {2*self.dark}     {6*self.sixteenth_note}{6*self.eighth_note}     {2*self.dark}\n {2*self.dark}   {8*self.sixteenth_note}{8*self.eighth_note}   {2*self.dark}\n{2*self.dark}    {6*self.sixteenth_note}{4*char}{6*self.eighth_note}    {2*self.dark}\n{2*self.dark}  {6*self.sixteenth_note}{8*char}{6*self.eighth_note}  {2*self.dark}\n{2*self.dark}  {6*self.eighth_note}{8*char}{6*self.sixteenth_note}  {2*self.dark}\n{2*self.dark}    {6*self.eighth_note}{4*char}{6*self.sixteenth_note}    {2*self.dark}\n {2*self.dark}   {8*self.eighth_note}{8*self.sixteenth_note}   {2*self.dark}\n {2*self.dark}     {6*self.eighth_note}{6*self.sixteenth_note}     {2*self.dark}\n  {2*self.dark}        {2*self.eighth_note}{2*self.sixteenth_note}        {2*self.dark}\n\n                       Frums', wait_time)
        for i in range(6):
            ender_pearl('\xea', 0, self.quarter_beat_time,2)
            ender_pearl('\xea', 0, self.quarter_beat_time,1)
            ender_pearl('.', 0, self.half_beat_time)
            ender_pearl('\xf7', 0, self.half_beat_time)
            ender_pearl('\xea', 0, self.half_beat_time)
            ender_pearl('.', 0, self.quarter_beat_time, 2)
            ender_pearl('.', 0, self.quarter_beat_time, 1)
            ender_pearl('\xf7', 0, self.half_beat_time)
            ender_pearl('\xea', 0, self.half_beat_time)
            ender_pearl('.', 0, self.half_beat_time)
            ender_pearl('\xea', 0, self.quarter_beat_time, 2)
            ender_pearl('\xea', 0, self.quarter_beat_time, 2)
            ender_pearl('.', 0, self.half_beat_time)
            ender_pearl('\xf7', 0, self.half_beat_time)
            ender_pearl('\xea', 1, self.quarter_beat_time, 2)
            ender_pearl('\xea', 1, self.quarter_beat_time, 1)
            if(i==5):break
            for k in range(8):
                ender_pearl('\xf1', 1, self.half_quarter_beat_time,2 if k==0 else 0)
                ender_pearl('.', 1, self.half_quarter_beat_time)
        ender_pearl('\xf1', 0, self.half_quarter_beat_time, 0)
        self.output(f'Credits\n\n  {self.light*2}{' '*20}{self.light*2}\n {self.light*2}{' '*22}{self.light*2}\n {self.light*2}{' '*7}{self.eighth_note * 4}{self.sixteenth_note*4}{' '*7}{self.light*2}\n{self.light*2}{' '*6}{6*self.eighth_note}{6*self.sixteenth_note}{' '*6}{self.light*2}\n{self.light*2}{' '*6}{6*self.eighth_note}{6*self.sixteenth_note}{' '*6}{self.light*2}\n{self.light*2}{' '*6}{6*self.sixteenth_note}{6*self.eighth_note}{' '*6}{self.light*2}\n{self.light*2}{' '*6}{6*self.sixteenth_note}{6*self.eighth_note}{' '*6}{self.light*2}\n {self.light*2}{' '*7}{self.eighth_note * 4}{self.sixteenth_note*4}{' '*7}{self.light*2}\n {self.light*2}{' '*22}{self.light*2}\n  {self.light*2}{' '*20}{self.light*2}\n\n                       Frums', self.half_quarter_beat_time)
        self.output(f'Credits\n\n  {self.light*2}{' '*20}{self.light*2}\n {self.light*2}{' '*22}{self.light*2}\n {self.light*2}{' '*22}{self.light*2}\n{self.light*2}{' '*10}{2*self.eighth_note}{2*self.sixteenth_note}{' '*10}{self.light*2}\n{self.light*2}{' '*8}{4*self.eighth_note}{4*self.sixteenth_note}{' '*8}{self.light*2}\n{self.light*2}{' '*8}{4*self.sixteenth_note}{4*self.eighth_note}{' '*8}{self.light*2}\n{self.light*2}{' '*10}{2*self.sixteenth_note}{2*self.eighth_note}{' '*10}{self.light*2}\n {self.light*2}{' '*22}{self.light*2}\n {self.light*2}{' '*22}{self.light*2}\n  {self.light*2}{' '*20}{self.light*2}\n\n                       Frums', self.half_quarter_beat_time)
        self.output(f'Credits{'\n'*13}                       Frums', self.quarter_beat_time + self.half_beat_time)
        time.sleep(self.half_beat_time)
        os.system('cls')

if __name__ == '__main__':
    Credits_BGA()