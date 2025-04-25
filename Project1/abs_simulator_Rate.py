import pandas as pd
import matplotlib.pyplot as plt
import tkinter as tk
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.ticker import MultipleLocator
import matplotlib

# 한글 폰트 설정
matplotlib.rc('font', family='Malgun Gothic')
matplotlib.rcParams['axes.unicode_minus'] = False

# CSV 데이터 불러오기
df = pd.read_csv("starforce_result_오차.csv")

# Tkinter 기본 설정
root = tk.Tk()
root.title("스타포스 확률 오차 시각화")

fig, ax = plt.subplots(figsize=(12, 6))
canvas = FigureCanvasTkAgg(fig, master=root)
canvas.get_tk_widget().pack()

# 공통 그래프 설정
def finalize_plot(title):
    ax.set_title(title)
    ax.set_xlabel("스타포스 단계")
    ax.set_ylabel("오차값 (%p)")
    ax.set_ylim(0, 2)
    ax.set_xticks(df["Level"])
    ax.set_yticks(range(0, 3))
    ax.yaxis.set_minor_locator(MultipleLocator(0.2))
    ax.grid(True, which='major', linestyle='-', linewidth=1)
    ax.grid(True, which='minor', linestyle=':', linewidth=0.5, color='gray')
    ax.legend()
    canvas.draw()

# 그래프 그리기 함수들
def show_success():
    ax.clear()
    ax.plot(df["Level"], df["Success"], label="성공 오차", marker='D', color='green', markersize=4)
    for i in range(len(df)):
        ax.text(df["Level"][i], df["Success"][i] + 0.1, f"{df['Success'][i]:.2f}", fontsize=6, color='green', ha='center')
    finalize_plot("성공 오차만 보기")

def show_fail():
    ax.clear()
    ax.plot(df["Level"], df["Fail"], label="실패 오차", marker='x', color='orange', markersize=4)
    for i in range(len(df)):
        ax.text(df["Level"][i], df["Fail"][i] + 0.1, f"{df['Fail'][i]:.2f}", fontsize=6, color='orange', ha='center')
    finalize_plot("실패 오차만 보기")

def show_destroy():
    ax.clear()
    ax.plot(df["Level"], df["Destroy"], label="파괴 오차", marker='.', color='red', markersize=4)
    for i in range(len(df)):
        ax.text(df["Level"][i], df["Destroy"][i] + 0.1, f"{df['Destroy'][i]:.2f}", fontsize=6, color='red', ha='center')
    finalize_plot("파괴 오차만 보기")

def show_all():
    ax.clear()
    ax.plot(df["Level"], df["Success"], label="성공 오차", marker='D', color='green', markersize=4)
    ax.plot(df["Level"], df["Fail"], label="실패 오차", marker='x', color='orange', markersize=4)
    ax.plot(df["Level"], df["Destroy"], label="파괴 오차", marker='.', color='red', markersize=4)
    for i in range(len(df)):
        ax.text(df["Level"][i], df["Success"][i] + 0.1, f"{df['Success'][i]:.2f}", fontsize=6, color='green', ha='center')
        ax.text(df["Level"][i], df["Fail"][i] + 0.1, f"{df['Fail'][i]:.2f}", fontsize=6, color='orange', ha='center')
        ax.text(df["Level"][i], df["Destroy"][i] + 0.1, f"{df['Destroy'][i]:.2f}", fontsize=6, color='red', ha='center')
    finalize_plot("전체 오차 보기")

# 버튼 프레임
button_frame = tk.Frame(root)
button_frame.pack(pady=10)

# 버튼들
tk.Button(button_frame, text="성공만 보기", command=show_success, width=15).grid(row=0, column=0, padx=5)
tk.Button(button_frame, text="실패만 보기", command=show_fail, width=15).grid(row=0, column=1, padx=5)
tk.Button(button_frame, text="파괴만 보기", command=show_destroy, width=15).grid(row=0, column=2, padx=5)
tk.Button(button_frame, text="모두 보기", command=show_all, width=15).grid(row=0, column=3, padx=5)

# 기본 그래프 출력
show_all()

root.mainloop()
