import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import tkinter as tk

# 데이터 로드
df = pd.read_csv("starforce_result.csv")

# 공통 라벨 표시 함수 (시뮬레이터 값만)
def label_sim_points():
    for i in range(len(df)):
        ax.text(df["Level"][i], df["Success"][i] + 3,
                f"{df['Success'][i]:.2f}", fontsize=6, color='green', ha='center', fontweight='bold')
        ax.text(df["Level"][i], df["Fail"][i] + 3,
                f"{df['Fail'][i]:.2f}", fontsize=6, color='orange', ha='center', fontweight='bold')
        ax.text(df["Level"][i], df["Destroy"][i] + 3,
                f"{df['Destroy'][i]:.2f}", fontsize=6, color='red', ha='center', fontweight='bold')

# 그래프 그리는 함수들
def draw_simulation_only():
    ax.clear()
    ax.plot(df["Level"], df["Success"], label="Sim - Success", marker='D', color='green', markersize=4)
    ax.plot(df["Level"], df["Fail"], label="Sim - Fail", marker='x', color='orange', markersize=4)
    ax.plot(df["Level"], df["Destroy"], label="Sim - Destroy", marker='.', color='red', markersize=6)
    label_sim_points()
    update_plot("simulator")

def draw_design_only():
    ax.clear()
    ax.plot(df["Level"], df["std_Success"], label="Design - Success", marker='D', linestyle='--', color='green', alpha=0.5)
    ax.plot(df["Level"], df["std_Fail"], label="Design - Fail",  marker='x', linestyle='--', color='orange', alpha=0.5)
    ax.plot(df["Level"], df["std_Destroy"], label="Design - Destroy", marker='.', linestyle='--', color='red', alpha=0.5)
    update_plot("signed")

def draw_both():
    ax.clear()
    # 시뮬레이터
    ax.plot(df["Level"], df["Success"], label="Sim - Success", marker='D', color='green', markersize=4)
    ax.plot(df["Level"], df["Fail"], label="Sim - Fail", marker='x', color='orange', markersize=4)
    ax.plot(df["Level"], df["Destroy"], label="Sim - Destroy", marker='.', color='red', markersize=6)
    label_sim_points()
    # 기획
    ax.plot(df["Level"], df["std_Success"], label="Design - Success", linestyle='--', color='green', alpha=0.5)
    ax.plot(df["Level"], df["std_Fail"], label="Design - Fail", linestyle='--', color='orange', alpha=0.5)
    ax.plot(df["Level"], df["std_Destroy"], label="Design - Destroy", linestyle='--', color='red', alpha=0.5)
    update_plot("simulator + signed")

# 공통 그래프 설정
def update_plot(title):
    ax.set_title(title)
    ax.set_xlabel("Starforce Level")
    ax.set_ylabel("Rate (%)")
    ax.set_ylim(0, 100)
    ax.set_xticks(df["Level"])
    ax.set_yticks(range(0, 101, 10))  # 주 눈금
    ax.set_yticks(range(0, 101, 5), minor=True)  # 소 눈금 추가
    ax.grid(True, which='major', linestyle='-', linewidth=1)
    ax.grid(True, which='minor', linestyle=':', linewidth=0.5)
    ax.legend()
    canvas.draw()

# Tkinter 윈도우 설정
root = tk.Tk()
root.title("Starforce 확률 비교 시각화")

fig, ax = plt.subplots(figsize=(10, 6))
canvas = FigureCanvasTkAgg(fig, master=root)
canvas.get_tk_widget().pack()

# 버튼들
button_frame = tk.Frame(root)
button_frame.pack(pady=10)

tk.Button(button_frame, text="시뮬레이터만 보기", command=draw_simulation_only, width=20).grid(row=0, column=0, padx=10)
tk.Button(button_frame, text="표기 확률만 보기", command=draw_design_only, width=20).grid(row=0, column=1, padx=10)
tk.Button(button_frame, text="둘 다 보기", command=draw_both, width=20).grid(row=0, column=2, padx=10)

# 기본 상태: 둘 다 보기
draw_both()

root.mainloop()
