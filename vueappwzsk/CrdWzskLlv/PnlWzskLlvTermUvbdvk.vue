<template>
	<v-card v-if=initdone class="pa-3 my-3 mx-auto" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="11">
					<div>{{tag.Cpt}}</div>
				</v-col>
				<v-col align="end">
					<v-btn-toggle v-model="contapp.ButClaimOn">
						<v-btn
							fab
							small
							light
							color="primary"
							v-on:click="handleButClick('ButClaimClick')"
							:value="1"
							:disabled="!statshr.ButClaimActive"
						>
							<v-icon color="white">{{contapp.ButClaimOn ? 'mdi-cog' : 'mdi-cog-off'}}</v-icon>
						</v-btn>
					</v-btn-toggle>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text>
			<v-text-field
				class="my-2"
				readonly
				outlined
				v-model="continf.TxtCst"
				:label="tag.CptCst"
			/>

			<v-divider/>

			<h3
				class="text-5 my-2"
			>
				{{tag.HdgDio}}
			</h3>

			<div
				class="my-2"
				style="height:200px"
			>
				<!-- IP divDat - IBEGIN -->
				<textarea 
					style="resize:none;font-size:12px;font-family:Monospace;font-weight:normal;width:685px;background-color:#000000;color:#ffffff;border-width:0px;"
					rows="8"
					cols="120"
					type="text"
					:value="continf.TxtDatLog"
					readonly="readonly"
				/>
				<!-- IP divDat - IEND -->
			</div>

			<v-divider/>

			<h3
				class="text-5 my-2"
			>
				{{tag.HdgCex}}
			</h3>

			<v-select
				class="my-2"
				v-model="contapp.fiFPupCmd"
				:items="feedFPupCmd"
				:label='tag.CptCmd'
				v-on:change="handlePupChange('numFPupCmd', contapp.fiFPupCmd)"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-text-field
				class="my-2"
				v-model="contiac.TxfCsq"
				:label="tag.CptCsq"
			/>

			<v-row class="my-2">
				<v-col>
					<v-btn
						class="my-2"
						color="primary"
						v-on:click="handleButClick('ButSmtClick')"
						:disabled="!statshr.ButSmtActive"
					>
						{{tag.ButSmt}}
					</v-btn>
				</v-col>
			</v-row>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzskLlvTermUvbdvk',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzskLlvTermUvbdvk.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit('request', {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(consref) {
				const dpchapp = {
					"DpchAppWzskLlvTermUvbdvkDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handlePupChange: function(cisref, fi) {
				this.contiac[cisref] = fi.num;

				this.updateEng(["contiac"]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzskLlvTermUvbdvk"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzskLlvTermUvbdvkData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzskLlvTermUvbdvkData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - RBEGIN -->
				*/
				if (dpcheng.ContIacWzskLlvTermUvbdvk) this.contiac = dpcheng.ContIacWzskLlvTermUvbdvk;
				if (dpcheng.ContInfWzskLlvTermUvbdvk) {
					let continf = dpcheng.ContInfWzskLlvTermUvbdvk;

					continf.TxtDatLog = continf.TxtDatLog.replace(/;/g, "\n");
	
					this.continf = continf;
				}
				if (dpcheng.FeedFPupCmd) this.feedFPupCmd = dpcheng.FeedFPupCmd;
				if (dpcheng.StatShrWzskLlvTermUvbdvk) this.statshr = dpcheng.StatShrWzskLlvTermUvbdvk;
				if (dpcheng.TagWzskLlvTermUvbdvk) {
					Wzsk.unescapeBlock(dpcheng.TagWzskLlvTermUvbdvk);
					this.tag = dpcheng.TagWzskLlvTermUvbdvk;
				}

				if (dpcheng.ContIacWzskLlvTermUvbdvk) {
					for (var i = 0; i < this.feedFPupCmd.length; i++)
						if (this.feedFPupCmd[i].num == this.contiac.numFPupCmd) {
							this.contapp.fiFPupCmd = this.feedFPupCmd[i];
							break;
						}
				}

				if (dpcheng.ContInfWzskLlvTermUvbdvk) {
					if (!this.continf.ButClaimOn) this.contapp.ButClaimOn = 0;
					else this.contapp.ButClaimOn = 1;
				}
				/*
				<!-- IP mergeDpchEngData - REND -->
				*/
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWzskVDpch, obj.dpcheng);
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWzskVDpch, dpcheng) {
				if (srefIxWzskVDpch == "DpchEngWzskLlvTermUvbdvkData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzskVDpch == "DpchEngWzskLlvTermUvbdvkData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
		},

		data: () => ({
			initdone: false,

			/*
			*/
			contapp: {
				fiFPupCmd: null,

				ButClaimOn: 0,
			},

			contiac: null,

			continf: null,

			feedFPupCmd: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
